//
//  ARMGameServerCommunicator.h
//  ARMonopolyNativeCodeBase
//
//  Created by Sam Howes on 3/13/14.
//  Copyright (c) 2014 Sam Howes. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const NSString *ARMGameServerErrorDomain;

typedef enum ARMGameServerErrorCode {
    ARMUnkownErrorCode,
    ARMInvalidPostDataErrorCode,
    ARMInvalidPutDataErrorCode,
    ARMInvalidServerResponseDataErrorCode,
    ARMGameServerErrorResponseErrorCode
} ARMGameServerErrorCode;

//--------------------------- URL/HTTP Constants ---------------------------//
extern const NSString *ARMGameServerURLString;
extern const NSString *kGSHTTPUserAgentHeaderString;
extern const NSString *kGSHTTPAcceptContentHeaderString;
extern const NSString *kGSHTTPClientCookieName;


extern const NSString *kGSLoginEndpointURLString;
extern const NSString *kGSImagesEndpointURLFormatString;
extern const NSString *kGSActiveSessionsEndpointURLString;
extern const NSString *kGSCreateSessionURLString;
extern const NSString *kGSJoinSessionEndpointURLString;
extern const NSString *kGSCreateSessionEndpointURLString;
extern const NSString *kGSLeaveSessionEndpointURLString;
extern const NSString *kGSGetPlayersInSessionEndpointURLFormatString;

//---------------------- HTTP Body Request Constants -----------------------//
extern const NSString *kGSUserNamePostKey;
extern const NSString *kGSDeviceIDPostKey;
extern const NSString *kGSSessionIDPostKey;
extern const NSString *kGSCreateSessionPostKey;

//--------------------- HTTP Body Response Constants ----------------------//
extern const NSString *kGSErrorReplyKey;
extern const NSString *kGSErrorCodeReplyKey;
extern const NSString *kGSErrorDescriptionReplyKey;
extern const NSString *kGSActiveSessionsReplyKey;
extern const NSString *kGSSessionNameReplyKey;
extern const NSString *kGSSessionIDReplyKey;
extern const NSString *kGSCurrentPlayersReplyKey;
extern const NSString *kGSPlayerNameReplyKey;
extern const NSString *kGSPlayerImageTargetIDReplyKey;
extern const NSString *kGSPlayerImageURLReplyKey;



typedef enum GameServerConnectionStatus {
    kNotInitialized,
    kLoggingIn,
    kSendingImage,
    kLoggedIn,
    kRetrievingGameSessions,
    kReadyForSelection,
    kJoiningGameSession,
    kCreatingGameSession,
    kInGameSession,
    kLeavingGameSession,
    kFailedToConnectToServer
} GameServerConnectionStatus;

typedef void (^CompletionHandlerType)(NSError *);
typedef void (^HTTPURLProcessorType)(NSHTTPURLResponse*, NSDictionary *);
typedef void (^ARMImageProcessorType)(NSHTTPURLResponse*, UIImage *);


@interface ARMGameServerCommunicator : NSObject <UITableViewDataSource>

@property GameServerConnectionStatus connectionStatus;
@property (strong, nonatomic) NSString *currentSessionID;
@property (strong, nonatomic) NSString *currentSessionName;
@property (strong, nonatomic) NSString *clientIDCookie;
@property (strong, nonatomic) NSMutableArray *availableGameSessions;


+ (id)sharedInstance;

- (void)finishTasksWithoutCompletionHandlerAndPreserveState;

- (void)continueTasksWithCompletionHandler;

- (void)loginWithCompletionHandler:(CompletionHandlerType)completionHandler;

- (void)putProfileImageToServerWithCompletionHandler:(CompletionHandlerType)completionHandler;

- (void)getActiveSessionsWithCompletionHandler:(CompletionHandlerType)completionHandler;

- (void)joinSessionWithIndex:(NSInteger)indexOfSessionToJoin completionHandler:(CompletionHandlerType)completionHandler;

- (void)leaveSessionWithCompletionHandler:(CompletionHandlerType)completionHandler;

- (void)createSessionWithName:(NSString *)newSessionName completionHandler:(CompletionHandlerType)completionHandler;

- (void)getCurrentPlayersInSessionWithCompletionHandler:(CompletionHandlerType)completionHandler;

- (void)downloadPlayerImagesWithCompletionHandler:(CompletionHandlerType)completionHandler;

@end