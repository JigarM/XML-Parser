//
//  Parser.m
//  Parsing Test
//
//  Created by Robert Ryan on 5/28/13.
//  Copyright (c) 2013 Robert Ryan. All rights reserved.
//

#import "Parser.h"

@interface Parser () <NSXMLParserDelegate>

@property (nonatomic, strong) NSMutableDictionary *item;     // while parsing, this is the item currently being parsed
@property (nonatomic, strong) NSMutableString *elementValue; // this is the element within that item being parsed

@end

@implementation Parser

// warn user if they accidentally try to set the delegate for this parser

- (void)setDelegate:(id<NSXMLParserDelegate>)delegate
{
    NSLog(@"%s: No need to set delegate. This parser is has its own delegate.", __FUNCTION__);
}

// parse, setting the delegate first

- (BOOL)parse
{
    [super setDelegate:self];
    return [super parse];
}

#pragma mark - NSXMLParserDelegate methods

- (void)parserDidStartDocument:(NSXMLParser *)parser
{
    self.items = [[NSMutableArray alloc] init];
    
    if (!self.rowElementName)
        NSLog(@"%s Warning: Failed to specify row identifier element name", __FUNCTION__);
}

- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributeDict
{
	if ([elementName isEqualToString:self.rowElementName])
    {
        self.item  = [[NSMutableDictionary alloc] init];
        
        for (NSString *attributeName in self.attributeNames)
        {
            id attributeValue = [attributeDict valueForKey:attributeName];
            if (attributeValue)
                [self.item setObject:attributeValue forKey:attributeName];
        }
    }
    else if ([self.elementNames containsObject:elementName])
    {
        self.elementValue = [[NSMutableString alloc] init];
    }
}

- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string
{
    if (self.elementValue)
    {
        [self.elementValue appendString:string];
    }
}

- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName
{
    if ([elementName isEqualToString:self.rowElementName])
    {
        [self.items addObject:self.item];
        self.item = nil;
    }
    else if ([self.elementNames containsObject:elementName])
    {
        [self.item setValue:self.elementValue forKey:elementName];
        self.elementValue = nil;
    }
}

@end
