//  Copyright (c) 2013 Rob Rix. All rights reserved.

@import Foundation;

typedef id (^RXFoldBlock)(id memo, id each, bool *stop); // memo is the initial value on the first invocation, and thereafter the value returned by the previous invocation of the block
typedef id (*RXFoldFunction)(id memo, id each, bool *stop); // memo is the initial value on the first invocation, and thereafter the value returned by the previous invocation of the function

/**
 Folds a `enumeration` with `block` or `function`, using `initial` as the `memo` argument to `block` or `function` for the first element.
 */
extern id RXFold(id<NSObject, NSCopying, NSFastEnumeration> enumeration, id initial, RXFoldBlock block);
extern id RXFoldF(id<NSObject, NSCopying, NSFastEnumeration> enumeration, id initial, RXFoldFunction function);


#pragma mark Constructors

/**
 Constructs an array with the elements of the specified traversal. The enumeration's elements must not be nil.
 */
extern NSArray *RXConstructArray(id<NSObject, NSCopying, NSFastEnumeration> enumeration);

/**
 Constructs a set with the elements of the specified enumeration. The enumeration's elements must not be nil.
 */
extern NSSet *RXConstructSet(id<NSObject, NSCopying, NSFastEnumeration> enumeration);

/**
 Constructs a dictionary with the elements of the specified enumeration. The enumeration's elements must not be nil, and must conform to RXKeyValuePair.
 */
extern NSDictionary *RXConstructDictionary(id<NSObject, NSCopying, NSFastEnumeration> enumeration);

/**
 Constructs a tuple with the elements of the specified enumeration. The enumeration's elements may be nil.
 */
@class RXTuple;
extern RXTuple *RXConstructTuple(id<NSObject, NSCopying, NSFastEnumeration> enumeration);
