//
//  APIManager.m
//  WSManager
//
//  Created by Huy Hoang  on 5/30/16.
//  Copyright © 2016 Huy Hoang . All rights reserved.
//

#import "APIManager.h"

#define WS_TIMEOUT      120

@implementation APIManager


+ (APIManager *)sharedInstance {
    static dispatch_once_t pred;
    static APIManager *shared = nil;
    
    dispatch_once(&pred, ^{
        shared = [[APIManager alloc] init];
    });
    return shared;
}

- (id)init {
    if (self = [super init]) {
        self.requestOperationManager = [AFHTTPRequestOperationManager manager];
        self.requestOperationManager.securityPolicy.allowInvalidCertificates = YES;
        // set max concurrent request, in this case I use 3. It's mean you can call upto 3 API at a time
        self.requestOperationManager.operationQueue.maxConcurrentOperationCount = 3;
    }
    
    return self;
}

- (APIBaseObject *)isBaseObject:(Class)c {
    id result = [c new];
    if ([result isKindOfClass:[APIBaseObject class]]) {
        return result;
    } else {
        return nil;
    }
}


- (void)sendPOSTRequestForAPI:(NSString*)urlAPI parameters:(NSDictionary*)parameters responseObjectClass:(Class)responseObjectClass responseHandler:(ServerResponseHandler)responseHandler isBackgroundCall: (BOOL) isBackgroundCall {
    NSMutableURLRequest *request = [[AFHTTPRequestSerializer serializer]requestWithMethod:@"POST" URLString: urlAPI parameters:parameters error:nil];
    [request setTimeoutInterval:WS_TIMEOUT];

    AFHTTPRequestOperation *operation = [[AFHTTPRequestOperation alloc] initWithRequest:request];

    operation.responseSerializer = [AFJSONResponseSerializer serializer];
    
    [operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject) {
        // check if input object is base object
        APIBaseObject *result = [self isBaseObject:responseObjectClass];
        
        if (result != nil) {
            // parse info to response object
            [result parseResponse:responseObject];
        }

        if (isBackgroundCall == NO) {
            // process common error
            [[APIErrorProcessor sharedInstance] process:result];
        }
        
        if (responseHandler) {
            responseHandler (YES, result);
        }
        
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        // if request fails
        if (isBackgroundCall == NO) {
            [[APIErrorProcessor sharedInstance] process:error];
        }
        
        if (responseHandler) {
            responseHandler (NO, nil);
        }
    }];
    [self.requestOperationManager.operationQueue addOperation:operation];
}


- (void)cancelAllRequest; {
    // cancel all request 
    [self.requestOperationManager.operationQueue cancelAllOperations];
}

@end
