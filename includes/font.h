/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:42:49 by azouiten          #+#    #+#             */
/*   Updated: 2021/07/13 14:10:08 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
#define FONT_H

#include <SDL.h>
#include "libft.h"
#define REGULAR 0x00
#define BOLD 0x01
#define LIGHT 0x02

// typedef struct s_ttf_file_header{
//   Uint16  major_version;
//   Uint16  minor_version;
//   Uint16  num_tables;
//   Uint16  search_range;
//   Uint16  entry_selector;
//   Uint16  range_shift;
// }               t_ttf_file_header;

// typedef struct s_ttf_file_tables{
//   char    name[4];      //table name
//   Uint64  checksum;     //Check sum
//   Uint64  offset;       //Offset from beginning of file
//   Uint64  lenght;       //length of the table in bytes
// }               t_ttf_file_tables;

// typedef struct s_name_table_header{
//   Uint16 FSelector;      //format selector. Always 0
//   Uint16 NRCount;        //Name Records count
//   Uint16 StorageOffset;  //Offset for strings storage, from 
//                           //start of the table
// }               t_name_table_header;
 
//Records in the names table
// typedef struct s_name_table_record{
//   Uint16 PlatformID;
//   Uint16 EncodingID;
//   Uint16 LanguageID;
//   Uint16 NameID;
//   Uint16 StringLength;
//   Uint16 StringOffset;    //from start of storage area
// }               t_name_table_record;

typedef struct  s_font
{
    char    *family;
    int     weight;
    char    *path;
    TTF_Font    *font;
}               t_font;

// t_font  *fetch_font_prop(char   *font_path);
// t_sdl_image     *font_manager(char *string, char   *font_family, int   weight);
t_font  *font_manager(char *font_path);
#endif