//
//  APIBaseObject.h
//  WSManager
//
//  Created by Huy Hoang  on 5/30/16.
//  Copyright © 2016 Huy Hoang . All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APIBaseObject : NSObject
// define common key here

// parse response return from server
- (void)parseResponse:(NSDictionary*)response;

@end
