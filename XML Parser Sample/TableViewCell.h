//
//  TableViewCell.h
//  XML Parser Sample
//
//  Created by Jigar M on 23/07/14.
//  Copyright (c) 2014 Jigar M. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *cellImageView;
@property (weak, nonatomic) IBOutlet UILabel *cellTitle;
@property (weak, nonatomic) IBOutlet UILabel *cellSubtitle;

@end
