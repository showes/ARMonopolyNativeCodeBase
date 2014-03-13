//
//  ARMPlayerInfo.h
//  ARMonopolyNativeCodeBase
//
//  Created by Sam Howes on 3/2/14.
//  Copyright (c) 2014 Samuel Howes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ARMNetworkViewController.h"

typedef enum GameServerConnectionStatus GameServerConnectionStatus;

@interface ARMPlayerInfo : NSObject

+ (id)sharedInstance;

/* Save the user data to a persistent archive on disk */
- (BOOL)saveInstanceToArchive;

/* If we have adequate data for use with the game server */
- (BOOL)isReadyForLogin;

// Local Player info
@property NSString *playerDisplayName;

@property UIImage *playerDisplayImage;

@property NSString *gameTileImageTargetID;

// Networking Properties
@property GameServerConnectionStatus lastConnectionStatus;
@property NSString *sessionID;
@property NSString *sessionName;
@property NSString *clientID;
@property NSMutableArray *playersInSessionArray;

@end
