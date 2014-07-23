//
//  NewsDetail.h
//  XML Parser Sample
//
//  Created by Jigar M on 23/07/14.
//  Copyright (c) 2014 Jigar M. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NewsDetail : UIViewController

@property (nonatomic, strong) NSString *newsTitle;
@property (nonatomic, strong) NSURL *url;

@property (weak, nonatomic) IBOutlet UIWebView *webView;

@end
