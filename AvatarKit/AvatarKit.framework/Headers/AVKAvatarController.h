//
//  AVKAvatarController.h
//  AvatarKit
//
//  Created by Hao Lee on 2017/7/12.
//  Copyright © 2017年 Speed 3D Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SceneKit/SceneKit.h>
#import <AvatarKit/AVKGender.h>
#import <AvatarKit/AVKPreset.h>

/**
 An `AVKAvatarController` class has a node of the avatar on a scene graph.
 You have to show the avatar, you need to add `sceneNode` in your scene.
 To modify style on the avatar, use methods of `AVKAvatarController` can immediately to update on the `sceneNode`.
 
 Save an Avatar
 
 AvatarKit provides to save an avatar to a file.
 `AVKAvatarController` class support the `NSSecureCoding` protocol.
 Use the `NSKeyedArchiver` class to serialize an avatar and all its contents, and the `NSKeyedUnarchiver` class to load an archived avatar.
 */
@interface AVKAvatarController : NSObject <NSSecureCoding>

/**
 The gender of avatar.
 */
@property(nonatomic, readonly) AVKGender avatarGender;

/**
 The version of avatar.
 */
@property(nonatomic, readonly) NSInteger version;

/**
 Returns a Boolean value indicating whether the scene node wears preset.
 */
@property(nonatomic, readonly) BOOL isWornPresets;

/**
 The node of the avatar on the scene graph.
 */
@property(nonatomic, strong, readonly, nonnull) SCNNode *sceneNode;

/**
 The camera can take full the avatar. Let `SCNView` displays your avatar.
 */
@property(class, nonatomic, strong, readonly, nonnull) SCNNode *defaultCameraNode;


/**
 Create a default avatar.
 
 @param gender
 The gender of default avatar.
 
 @return A default Avatar Controller object.
 */
- (nonnull instancetype)initWithGenderOfDefaultAvatar:(AVKGender)gender;

/**
 Adds an observe handler for wears on this avatar.
 
 @param completed
 A block which is called to have worn clothes.
 */
- (void)observeAvatarHasWornPresets:(void (^ _Nonnull)(SCNNode * _Nonnull node))completed;

/**
 Let this avatar wears a suit, coat, shirt and so on.
 
 @param suit
 Select your want to wear clothes that from `+[AVKPreset getPresetsForType:gender:]`.
 
 @param block
 Notification the avatar has worn clothes. If `error` isn't `nil` when the avatar cannot wear clothes.
 */
- (void)setSuit:(nonnull AVKPreset *)suit completionHandler:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))block;

/**
 Let this avatar has a motion.
 
 @param motion
 Select your want motion that from `+[AVKPreset getPresetsForType:gender:]`.
 
 @param block
 Notification the avatar has motion. If `error` isn't `nil` when the avatar cannot use motion.
 */
- (void)setMotion:(nonnull AVKPreset *)motion completionHandler:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))block;

/**
 Let this avatar designs hairstyle.
 
 @param hair
 Select your want to design hairstyle that from `+[AVKPreset getPresetsForType:gender:]`.
 
 @param block
 Notification the avatar has designed hairstyle. If `error` isn't `nil` when the avatar cannot design hairstyle.
 */
- (void)setHair:(nonnull AVKPreset *)hair completionHandler:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))block;

/**
 Let this avatar wears an accessory.
 
 @param accessory
 Select your want to wear accessory that from `+[AVKPreset getPresetsForType:gender:]`.
 
 @param block
 Notification the avatar has worn accessory. If `error` isn't `nil` when the avatar cannot wear accessory.
 */
- (void)setAccessory:(nullable AVKPreset *)accessory completionHandler:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))block;

/**
 Changes facial at the avatar.
 We have more basic facial, the respective `weights` into the array where you can make the avatar show different facials.
 The `weights` range is 0-1.
 */
- (void)setFacialWithWeights:(nonnull NSArray<NSNumber *> *)weights;

@end
