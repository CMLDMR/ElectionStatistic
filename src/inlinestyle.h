#ifndef INLINESTYLE_H
#define INLINESTYLE_H


#include <iostream>
#include <string>


namespace Style {
    [[maybe_unused]] inline const std::string style{"style"};
    inline const std::string dataoid{"data-oid"};
    inline const std::string userdata1{"userData1"};
    inline const std::string userdata2{"userData2"};
    inline const std::string customData{"customDatas"};
    namespace color {
        inline const std::string rgb(const std::string &rgb){return std::string{"color:rgb("+rgb+");"};};
        inline const std::string rgba(const std::string &rgba){return std::string{"color:rgba("+rgba+");"};};
        inline const std::string color(const std::string &color){return std::string{"color:"+color+";"};};
        namespace Pink {
            inline const std::string Pink {"Pink ;"};
            inline const std::string LightPink {"LightPink ;"};
            inline const std::string HotPink {"HotPink ;"};
            inline const std::string DeepPink {"DeepPink ;"};
            inline const std::string PaleVioletRed {"PaleVioletRed ;"};
            inline const std::string MediumVioletRed {"MediumVioletRed ;"};
        }
        namespace Purple {
            [[maybe_unused]] inline const std::string LightSkyBlue {"lightskyblue ;"};
            [[maybe_unused]] inline const std::string Lavender {"Lavender ;"};
            [[maybe_unused]] inline const std::string Thistle  {"Thistle ;"};
            [[maybe_unused]] inline const std::string Plum  {"Plum ;"};
            [[maybe_unused]] inline const std::string Orchid  {"Orchid ;"};
            [[maybe_unused]] inline const std::string Violet  {"Violet ;"};
            [[maybe_unused]] inline const std::string Fuchsia  {"Fuchsia ;"};
            [[maybe_unused]] inline const std::string Magenta  {"Magenta ;"};
            [[maybe_unused]] inline const std::string MediumOrchid  {"MediumOrchid ;"};
            [[maybe_unused]] inline const std::string DarkOrchid  {"DarkOrchid ;"};
            [[maybe_unused]] inline const std::string DarkViolet  {"DarkViolet ;"};
            [[maybe_unused]] inline const std::string DodgerBlue  {"DodgerBlue ;"};
            [[maybe_unused]] inline const std::string BlueViolet  {"BlueViolet ;"};
            [[maybe_unused]] inline const std::string DarkMagenta   {"DarkMagenta ;"};
            [[maybe_unused]] inline const std::string Purple   {"Purple ;"};
            [[maybe_unused]] inline const std::string MediumPurple   {"MediumPurple ;"};
            [[maybe_unused]] inline const std::string MediumSlateBlue   {"MediumSlateBlue ;"};
            [[maybe_unused]] inline const std::string SlateBlue   {"SlateBlue ;"};
            [[maybe_unused]] inline const std::string DarkSlateBlue   {"DarkSlateBlue ;"};
            [[maybe_unused]] inline const std::string RebeccaPurple   {"RebeccaPurple ;"};
            [[maybe_unused]] inline const std::string Indigo {"Indigo ;"};
            [[maybe_unused]] inline const std::string MidnightBlue{"MidnightBlue;"};
            [[maybe_unused]] inline const std::string RoyalBlue{"RoyalBlue;"};
        }
        namespace Red {
            [[maybe_unused]] inline const std::string LightSalmon  {"LightSalmon ;"};
            [[maybe_unused]] inline const std::string Salmon   {"Salmon ;"};
            [[maybe_unused]] inline const std::string DarkSalmon   {"DarkSalmon ;"};
            [[maybe_unused]] inline const std::string LightCoral   {"LightCoral ;"};
            [[maybe_unused]] inline const std::string IndianRed    {"IndianRed ;"};
            [[maybe_unused]] inline const std::string Crimson   {"Crimson ;"};
            [[maybe_unused]] inline const std::string Red   {"Red ;"};
            [[maybe_unused]] inline const std::string FireBrick   {"FireBrick ;"};
            [[maybe_unused]] inline const std::string DarkRed   {"DarkRed ;"};
        }
        namespace Orange {
            [[maybe_unused]] inline const std::string Orange  {"Orange ;"};
            [[maybe_unused]] inline const std::string DarkOrange    {"DarkOrange ;"};
            [[maybe_unused]] inline const std::string Coral    {"Coral ;"};
            [[maybe_unused]] inline const std::string Tomato    {"Tomato ;"};
            [[maybe_unused]] inline const std::string OrangeRed     {"OrangeRed ;"};
            [[maybe_unused]] inline const std::string GoldenRod     {"GoldenRod ;"};
        }
        namespace Yellow {
            [[maybe_unused]] inline const std::string Gold{"Gold;"};
            [[maybe_unused]] inline const std::string Yellow{"Yellow;"};
            [[maybe_unused]] inline const std::string LightYellow{"LightYellow;"};
            [[maybe_unused]] inline const std::string LemonChiffon{"LemonChiffon;"};
            [[maybe_unused]] inline const std::string LightGoldenRodYellow{"LightGoldenRodYellow;"};
            [[maybe_unused]] inline const std::string PapayaWhip{"PapayaWhip;"};
            [[maybe_unused]] inline const std::string Moccasin{"Moccasin;"};
            [[maybe_unused]] inline const std::string PeachPuff{"PeachPuff;"};
            [[maybe_unused]] inline const std::string PaleGoldenRod{"PaleGoldenRod;"};
            [[maybe_unused]] inline const std::string Khaki{"Khaki;"};
            [[maybe_unused]] inline const std::string DarkKhaki{"DarkKhaki;"};
        }
        namespace Green {
            [[maybe_unused]] inline const std::string GreenYellow{"GreenYellow;"};
            [[maybe_unused]] inline const std::string Chartreuse{"Chartreuse;"};
            [[maybe_unused]] inline const std::string LawnGreen{"LawnGreen;"};
            [[maybe_unused]] inline const std::string Lime{"Lime;"};
            [[maybe_unused]] inline const std::string LimeGreen{"LimeGreen;"};
            [[maybe_unused]] inline const std::string PaleGreen{"PaleGreen;"};
            [[maybe_unused]] inline const std::string LightGreen{"LightGreen;"};
            [[maybe_unused]] inline const std::string MediumSpringGreen{"MediumSpringGreen;"};
            [[maybe_unused]] inline const std::string SpringGreen{"SpringGreen;"};
            [[maybe_unused]] inline const std::string MediumSeaGreen{"MediumSeaGreen;"};
            [[maybe_unused]] inline const std::string SeaGreen{"SeaGreen;"};
            [[maybe_unused]] inline const std::string ForestGreen{"ForestGreen;"};
            [[maybe_unused]] inline const std::string Green{"Green;"};
            [[maybe_unused]] inline const std::string DarkGreen{"DarkGreen;"};
            [[maybe_unused]] inline const std::string YellowGreen{"YellowGreen;"};
            [[maybe_unused]] inline const std::string OliveDrab{"OliveDrab;"};
            [[maybe_unused]] inline const std::string DarkOliveGreen{"DarkOliveGreen;"};
            [[maybe_unused]] inline const std::string MediumAquaMarine{"MediumAquaMarine;"};
            [[maybe_unused]] inline const std::string DarkSeaGreen{"DarkSeaGreen;"};
            [[maybe_unused]] inline const std::string LightSeaGreen{"LightSeaGreen;"};
            [[maybe_unused]] inline const std::string DarkCyan{"DarkCyan;"};
            [[maybe_unused]] inline const std::string Teal{"Teal;"};
        }
        namespace White {
            [[maybe_unused]] inline const std::string White{"White;"};
            [[maybe_unused]] inline const std::string Snow{"Snow;"};
            [[maybe_unused]] inline const std::string HoneyDew{"HoneyDew;"};
            [[maybe_unused]] inline const std::string MintCream {"MintCream;"};
            [[maybe_unused]] inline const std::string Azure{"Azure;"};
            [[maybe_unused]] inline const std::string AliceBlue{"AliceBlue;"};
            [[maybe_unused]] inline const std::string GhostWhite{"GhostWhite;"};
            [[maybe_unused]] inline const std::string WhiteSmoke{"WhiteSmoke;"};
            [[maybe_unused]] inline const std::string SeaShell{"SeaShell;"};
            [[maybe_unused]] inline const std::string OldLace{"OldLace;"};
            [[maybe_unused]] inline const std::string FloralWhite{"FloralWhite;"};
            [[maybe_unused]] inline const std::string Ivory{"Ivory;"};
            [[maybe_unused]] inline const std::string AntiqueWhite{"AntiqueWhite;"};
            [[maybe_unused]] inline const std::string Linen{"Linen;"};
            [[maybe_unused]] inline const std::string LavenderBlush{"LavenderBlush;"};
            [[maybe_unused]] inline const std::string MistyRose{"MistyRose;"};
        }
        namespace Grey {
            [[maybe_unused]] inline const std::string Gainsboro{"Gainsboro;"};
            [[maybe_unused]] inline const std::string LightGray{"LightGray;"};
            [[maybe_unused]] inline const std::string Silver{"Silver;"};
            [[maybe_unused]] inline const std::string DarkGray {"DarkGray;"};
            [[maybe_unused]] inline const std::string DimGray{"DimGray;"};
            [[maybe_unused]] inline const std::string Gray{"Gray;"};
            [[maybe_unused]] inline const std::string LightSlateGray{"LightSlateGray;"};
            [[maybe_unused]] inline const std::string SlateGray{"SlateGray;"};
            [[maybe_unused]] inline const std::string DarkSlateGray{"DarkSlateGray;"};
            [[maybe_unused]] inline const std::string Black{"Black;"};
        }
    }


    namespace Affix {
        [[maybe_unused]] inline const std::string data_spy{"data-spy"};
        [[maybe_unused]] inline const std::string affix{"affix"};
        [[maybe_unused]] inline const std::string affix_top{"affix-top"};
        [[maybe_unused]] inline const std::string affix_bottom{"affix-bottom"};
        [[maybe_unused]] inline const std::string offsetTop( int offsetTop = 0 ){ return "data-offset-top=\""+std::to_string(offsetTop)+"\"";}
        [[maybe_unused]] inline const std::string offsetBottom( int offsetBottom = 0 ){ return "data-offset-bottom=\""+std::to_string(offsetBottom)+"\"";}
    }


    namespace font {
        namespace size {
            [[maybe_unused]] inline const std::string s72px{"font-size:72px;"};
            [[maybe_unused]] inline const std::string s64px{"font-size:64px;"};
            [[maybe_unused]] inline const std::string s48px{"font-size:48px;"};
            [[maybe_unused]] inline const std::string s36px{"font-size:36px;"};
            [[maybe_unused]] inline const std::string s28px{"font-size:28px;"};
            [[maybe_unused]] inline const std::string s24px{"font-size:24px;"};
            [[maybe_unused]] inline const std::string s20px{"font-size:20px;"};
            [[maybe_unused]] inline const std::string s18px{"font-size:18px;"};
            [[maybe_unused]] inline const std::string s16px{"font-size:16px;"};
            [[maybe_unused]] inline const std::string s14px{"font-size:14px;"};
            [[maybe_unused]] inline const std::string s12px{"font-size:12px;"};
            [[maybe_unused]] inline const std::string s11px{"font-size:11px;"};
            [[maybe_unused]] inline const std::string s10px{"font-size:10px;"};
            [[maybe_unused]] inline const std::string s9px{"font-size:9px;"};
            [[maybe_unused]] inline const std::string s8px{"font-size:8px;"};
        }
        namespace family {
            [[maybe_unused]] inline const std::string tahoma{"font-family:tahoma;"};
            [[maybe_unused]] inline const std::string dosis{"font-family: 'Dosis', sans-serif;"};
        }
        namespace weight {
            [[maybe_unused]] inline const std::string bold{"font-weight:bold;"};
            [[maybe_unused]] inline const std::string normal{"font-weight:normal;"};
            [[maybe_unused]] inline const std::string lighter{"font-weight:lighter;"};
        }
    }

    namespace background {
        [[maybe_unused]] inline std::string url(const std::string& imgPath){return std::string{"background:url("+imgPath+");"};};

        namespace color {
            [[maybe_unused]] inline const std::string rgb(const std::string& rgb){return std::string{"background-color:rgb("+rgb+");"};};
            [[maybe_unused]] inline const std::string rgb(int r , int g , int b ){return std::string{ "background-color:rgb(" +std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+");" };};
            [[maybe_unused]] inline const std::string rgba(int r , int g , int b , double a = 0.5 ){return std::string{ "background-color:rgba(" +std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+","+std::to_string(a)+");" };};
            [[maybe_unused]] inline const std::string rgba(const std::string& rgba){return std::string{"background-color:rgba("+rgba+");"};};
            [[maybe_unused]] inline const std::string color(const std::string& color){return std::string{"background-color:"+color};};
        }

        namespace size {
            [[maybe_unused]] inline const std::string contain{"background-size:contain;"};
            [[maybe_unused]] inline const std::string initial{"background-size:initial;"};
            [[maybe_unused]] inline const std::string cover{"background-size:cover;"};
            [[maybe_unused]] inline const std::string auto_{"background-size:auto;"};
            [[maybe_unused]] inline const std::string length(const std::string &inpixel){return std::string{"background-size:"+inpixel+"px;"};};
            [[maybe_unused]] inline const std::string length(const std::string &inpixel1,const std::string &inpixel2){return std::string{"background-size:"+inpixel1+"px "+inpixel2+"px;"};};
            [[maybe_unused]] inline const std::string percentage(const std::string &inper){return std::string{"background-size:"+inper+";"};};
            [[maybe_unused]] inline const std::string percentage(const std::string &inper1,const std::string &inper2){return std::string{"background-size:"+inper1+" "+inper2+";"};};
        }
        namespace repeat {
            [[maybe_unused]] inline const std::string repeat{"background-repeat:repeat;"};
            [[maybe_unused]] inline const std::string repeat_x{"background-repeat:repeat-x;"};
            [[maybe_unused]] inline const std::string repeat_y{"background-repeat:repeat-y;"};
            [[maybe_unused]] inline const std::string repeat_x_y{"background-repeat:repeat-x-y;"};
            [[maybe_unused]] inline const std::string norepeat{"background-repeat:no-repeat;"};
            [[maybe_unused]] inline const std::string round{"background-repeat:round;"};
            [[maybe_unused]] inline const std::string space{"background-repeat:space;"};
        }
        namespace origin {
            [[maybe_unused]] inline const std::string padding_box{"background-origin:padding-box;"};
            [[maybe_unused]] inline const std::string border_box{"background-origin:border-box;"};
            [[maybe_unused]] inline const std::string content_box{"background-origin:content-box;"};
        }
        namespace attachment {
            [[maybe_unused]] inline const std::string scroll{"background-attachment:scroll;"};
            [[maybe_unused]] inline const std::string fixed{"background-attachment:fixed;"};
            [[maybe_unused]] inline const std::string local{"background-attachment:local;"};
        }
        namespace blend_mode {
            [[maybe_unused]] inline const std::string normal{"background-blend-mode:normal;"};
            [[maybe_unused]] inline const std::string multiply{"background-blend-mode:multiply;"};
            [[maybe_unused]] inline const std::string screen{"background-blend-mode:screen;"};
            [[maybe_unused]] inline const std::string overlay{"background-blend-mode:overlay;"};
            [[maybe_unused]] inline const std::string darken{"background-blend-mode:darken;"};
            [[maybe_unused]] inline const std::string lighten{"background-blend-mode:lighten;"};
            [[maybe_unused]] inline const std::string color_dodge{"background-blend-mode:color-dodge;"};
            [[maybe_unused]] inline const std::string saturation{"background-blend-mode:saturation;"};
            [[maybe_unused]] inline const std::string color{"background-blend-mode:color;"};
            [[maybe_unused]] inline const std::string luminosity{"background-blend-mode:luminosity;"};
        }
        namespace clip {
            [[maybe_unused]] inline const std::string border_box{"background-clip:border-box;"};
            [[maybe_unused]] inline const std::string padding_box{"background-clip:padding-box;"};
            [[maybe_unused]] inline const std::string content_box{"background-clip:content-box;"};
        }
        namespace position {
            [[maybe_unused]] inline const std::string left_top{"background-position:left top;"};
            [[maybe_unused]] inline const std::string left_center{"background-position:left center;"};
            [[maybe_unused]] inline const std::string left_bottom{"background-position:left bottom;"};
            [[maybe_unused]] inline const std::string right_top{"background-position:right top;"};
            [[maybe_unused]] inline const std::string right_center{"background-position:right center;"};
            [[maybe_unused]] inline const std::string right_bottom{"background-position:right bottom;"};
            [[maybe_unused]] inline const std::string center_top{"background-position:center top;"};
            [[maybe_unused]] inline const std::string center_center{"background-position:center center;"};
            [[maybe_unused]] inline const std::string center_bottom{"background-position:center bottom;"};
            [[maybe_unused]] inline const std::string pos(const std::string &xpos , const std::string &ypos){return std::string{"background-position:"+xpos+" "+ypos+";"};};
            [[maybe_unused]] inline const std::string percentage(const std::string &per1 , const std::string &per2){return std::string{"background-position:"+per1+"% "+per2+"%;"};};
        }
    }

    namespace Border {
        [[maybe_unused]] inline const std::string border(const std::string &borderText){return std::string{"border:"+borderText+";"};};
        [[maybe_unused]] inline const std::string borderRardius(const std::string &radius1, const std::string &radius2 = "0" , const std::string &radius3 = "0" , const std::string &radius4 = "0")
        {return std::string{"border-radius:"+radius1+"px "+radius2+"px "+radius3+"px "+radius4+"px;"};};
        namespace width {
            [[maybe_unused]] inline const std::string medium{"-width:medium;"};
            [[maybe_unused]] inline const std::string thin{"-width:thin;"};
            [[maybe_unused]] inline const std::string thick{"-width:thick;"};
            [[maybe_unused]] inline const std::string length(const std::string &inpixel){return std::string{"-width:"+inpixel+"px;"};};
        }
        namespace style {
            [[maybe_unused]] inline const std::string none{"-style:none;"};
            [[maybe_unused]] inline const std::string hidden{"-style:hidden;"};
            [[maybe_unused]] inline const std::string dotted{"-style:dotted;"};
            [[maybe_unused]] inline const std::string dashed{"-style:dashed;"};
            [[maybe_unused]] inline const std::string solid{"-style:solid;"};
            [[maybe_unused]] inline const std::string double_{"-style:double;"};
            [[maybe_unused]] inline const std::string groove{"-style:groove;"};
            [[maybe_unused]] inline const std::string ridge{"-style:ridge;"};
            [[maybe_unused]] inline const std::string inset{"-style:inset;"};
            [[maybe_unused]] inline const std::string outset{"-style:outset;"};
        }
        namespace bottom {
            [[maybe_unused]] inline const std::string border(std::string borderText) {return std::string{"border-bottom:"+borderText+";"};};
            [[maybe_unused]] inline const std::string border_width(std::string Borderwidth){ return "border-bottom:"+Borderwidth;};
            [[maybe_unused]] inline const std::string border_style(std::string Borderstyle){ return "border-bottom:"+Borderstyle;};
            [[maybe_unused]] inline const std::string border_color(std::string rgb,std::string a = "1"){ return "border-bottom-color:rgb("+rgb+","+a+");";};
        }
        namespace right {
            [[maybe_unused]] inline const std::string border(std::string borderText){return std::string{"border-right:"+borderText+";"};};
            [[maybe_unused]] inline const std::string border_width(std::string Borderwidth){ return "border-right:"+Borderwidth;};
            [[maybe_unused]] inline const std::string border_style(std::string Borderstyle){ return "border-right:"+Borderstyle;};
            [[maybe_unused]] inline const std::string border_color(std::string rgb,std::string a = "1"){ return "border-right-color:rgb("+rgb+","+a+");";};
        }
        namespace left {
            [[maybe_unused]] inline const std::string border(std::string borderText){return std::string{"border-left:"+borderText+";"};};
            [[maybe_unused]] inline const std::string border_width(std::string Borderwidth){ return "border-left:"+Borderwidth;};
            [[maybe_unused]] inline const std::string border_style(std::string Borderstyle){ return "border-left:"+Borderstyle;};
            [[maybe_unused]] inline const std::string border_color(std::string rgb,std::string a = "1"){ return "border-left-color:rgb("+rgb+","+a+");";};
        }
        namespace top {
            [[maybe_unused]] inline const std::string border(std::string borderText){return std::string{"border-top:"+borderText+";"};};
            [[maybe_unused]] inline const std::string border_width(std::string Borderwidth){ return "border-top:"+Borderwidth;};
            [[maybe_unused]] inline const std::string border_style(std::string Borderstyle){ return "border-top:"+Borderstyle;};
            [[maybe_unused]] inline const std::string border_color(std::string rgb,std::string a = "1"){return "border-top-color:rgb("+rgb+","+a+");";};
        }
    }


    namespace Height {
        [[maybe_unused]] inline const std::string height(std::string value,std::string type = "px"){return std::string{"height:"+value+type+";"};};
    }



}



#endif // INLINESTYLE_H
