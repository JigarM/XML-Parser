//
//  Parser.h
//  Simple Parser
//
//  Created by Robert Ryan on 5/28/13.
//  Copyright (c) 2013 Robert Ryan. All rights reserved.
//

#import <Foundation/Foundation.h>

/** A `NSXMLParser` subclass for parsing XML feeds that are represented by a simple array of items, such as a RSS feed. The process is as follows:
 
 - Initialize the Parser using the standard `NSXMLParser` initialization methods (e.g. `initWithContentsOfURL`);
 
 - Set the `rowElementName` string and `elementNames` array based upon the format of your XML;
 
 - Call the standard `NSXMLParser` instance method, `parse` to initiate the parsing process.
 
For example, you might have have some code that says:

    NSURL *url = [NSURL URLWithString:@"http://rss.news.yahoo.com/rss"];
    Parser *parser = [[Parser alloc] initWithContentsOfURL:url];
    parser.rowElementName = @"item";
    parser.elementNames = @[@"title", @"description", @"link", @"pubDate"];
    [parser parse];

The array of dictionary items is now in `parser.items`. For example
 
    NSDictionary *firstItem = parser.items[0];
    NSString *title = firstItem[@"title"];

 */

@interface Parser : NSXMLParser

/**---------------------------------------------------------------------------------------
 * @name Configuring the parser
 *  ---------------------------------------------------------------------------------------
 */

/** @property   rowElementName
 
    @abstract   The element name that identifies a new row of data in the XML.
 */
 
@property (nonatomic, copy) NSString *rowElementName;

/** @property   attributeNames
 
    @abstract   The array of attributes we might want to retrieve for that row element name.
 */

@property (nonatomic, copy) NSArray *attributeNames;

/** @property   elementNames
 
    @abstract   The list of sub element names for which we're retrieving values.
 */

@property (nonatomic, copy) NSArray *elementNames;

/**---------------------------------------------------------------------------------------
 * @name Retrieving results
 *  ---------------------------------------------------------------------------------------
 */

/** @property   items
 
    @abstract   After parsing, this is the array of parsed items.
 */

@property (nonatomic, strong) NSMutableArray *items;

@end
