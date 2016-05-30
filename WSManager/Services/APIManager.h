//
//  APIManager.h
//  WSManager
//
//  Created by Huy Hoang  on 5/30/16.
//  Copyright © 2016 Huy Hoang . All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APIBaseObject.h"
#import "APIErrorProcessor.h"
#import <AFHTTPRequestOperationManager.h>


// block that handle response return from API
typedef void(^ServerResponseHandler) (BOOL success, APIBaseObject *response);

@interface APIManager : NSObject

// has NSOperationQueue that handle all request
@property (nonatomic, strong) AFHTTPRequestOperationManager *requestOperationManager;


// singleton - public method
+ (APIManager *)sharedInstance;


/*
 @urlAPI: URL of API request
 @parameters: parameters send to server
 @responseObjectClass: Object Model that response from server
 @responseHandler: (BOOL success, APIBaseObject *response) --> return status of request and object 
 @isBackgroundCall: check if it's background call so we may not show user message in this case
 
 */
- (void)sendPOSTRequestForAPI:(NSString*)urlAPI parameters:(NSDictionary*)parameters responseObjectClass:(Class)responseObjectClass responseHandler:(ServerResponseHandler)responseHandler isBackgroundCall: (BOOL) isBackgroundCall;

// Cancel all current request if they are requesting or in the queue
- (void)cancelAllRequest;


@end
