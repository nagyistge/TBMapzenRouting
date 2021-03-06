//
//  TBMapzenRoutingPoint.h
//  TBMapzenRouting
//
//  Created by Jesse Crocker on 7/19/16.
//
//

#import <Foundation/Foundation.h>
#import "TBMapzenRoutingTypes.h"

@interface TBMapzenRoutingPoint : NSObject

/** Coordinate of the point */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/** Type of location, either break or through. A break is a stop, so the first and last locations must be of type break. A through location is one that the route path travels through, and is useful to force a route to go through location. The path is not allowed to reverse direction at the through locations. If no type is provided, the type is assumed to be a break. */
@property (nonatomic, assign) TBMapzenRoutingPointType type;

/** (optional) Preferred direction of travel for the start from the location. This can be useful for mobile routing where a vehicle is traveling in a specific direction along a road, and the route should start in that direction. The heading is indicated in degrees from north in a clockwise direction, where north is 0°, east is 90°, south is 180°, and west is 270°. */
@property (nonatomic, strong, nullable) NSNumber *heading;

/** Create a new point.
 */
+ (instancetype _Nonnull)pointWithCoordinate:(CLLocationCoordinate2D)coordinate type:(TBMapzenRoutingPointType)type;

/** Get the dictionary representation of the point, used for creating server query. */
- (NSDictionary * _Nonnull)asDictionary;

@end
