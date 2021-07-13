/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:07:00 by azouiten          #+#    #+#             */
/*   Updated: 2021/07/13 14:21:15 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libui.h>

// t_font  *fetch_font_prop(char   *font_path)
// {
//     // int    ttf_file;
//     // t_ttf_file_header   file_header;
//     // t_font  *font;
//     // t_ttf_file_tables   table;
//     // int     i;

//     // TTF_Font *blob;
//     // ttf_file = open(font_path, O_RDONLY);
//     // read(ttf_file, &file_header, sizeof(t_ttf_file_header));
//     // printf("|%d|%d|%d|%d|%d|%d|\n", file_header.major_version, file_header.minor_version, file_header.num_tables,file_header.search_range,file_header.entry_selector,file_header.range_shift);
//     // i = 0;
//     // while (i < file_header.num_tables)
//     // {
//     //     read(ttf_file, &table, sizeof(t_ttf_file_tables));
//     //     if (!ft_strncmp(table.name, "name", 4))
//     //         printf("|%s|%llu|%llu|%llu|\n", table.name, table.checksum, table.length,table.offset);
//     //     i++;
//     // }
//     return(font);
// }

// t_sdl_image     *ft_make_image(TTF_Font *font, char *string)
// {
//     SDL_Surface *text;
//     t_sdl_image *image;

//     text = TTF_RenderText_Blended(font, string, (SDL_Color){RGB_R(255), RGB_G(255), RGB_B(255), RGB_A(1)});
//     SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, text);
//     SDL_Rect Message_rect;
//     Message_rect.x = 0;
//     Message_rect.y = 0;
//     Message_rect.w = 100;
//     Message_rect.h = 100;
//     image = NULL;
//     return (image);
// }

static  int ft_strcasecmp(char  *str1, char *str2)
{
    int i;
    
    i = 0;
    while (str1[i] && str2[i] && (str1[i] == str2[i] || (str1[i] - str2[i]) == 32 || (str1[i] - str2[i]) == -32))
        i++;
    return (str1[i] - str2[i]);
}

static  int get_weights(char    *weights)
{
    char    **tab_weights;
    int     weight;
    int     i;

    i = 0;
    tab_weights = ft_strsplit(weights, ' ');
    weight = REGULAR;
    while (tab_weights[i])
    {
        if (!ft_strcasecmp(tab_weights[i], "light"))
            weight = LIGHT;
        else if(!ft_strcasecmp(tab_weights[i], "bold"))
            weight = BOLD;
        else if(!ft_strcasecmp(tab_weights[i], "bold"))
            weight = LIGHT;
        else if(!ft_strcasecmp(tab_weights[i], "bold"))
            weight = LIGHT;
        i++;
    }
    printf("%i\n", BOLD);
    return (weight);
}

t_font  *font_manager(char *font_path)
{
    TTF_Font    *font;
    t_font      *font_data;
    
    // TTF_Init();
    font_data = (t_font*)malloc(sizeof(t_font));
    font = TTF_OpenFont(font_path, 25);
    if (!font)
        exit(1);
    font_data->family = TTF_FontFaceFamilyName(font);
    font_data->weight = get_weights(TTF_FontFaceStyleName(font));
    font_data->path = ft_strdup(font_path);
    font_data->font = font;
    printf("|%s|%d|%s|\n", font_data->family, font_data->weight, font_data->path);
    //add to the hashtable
    printf("\n{%s}\n", TTF_FontFaceStyleName(font));
    return (font_data);
}