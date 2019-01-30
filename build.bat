@echo off
REM Batch file for automated binary creation
echo Compiling source...
echo.
windres res\iconresource.rc -O coff -o obj\icon.res
mingw32-make
echo.
echo Converting maps and adding them to data...
echo.
cd tiled
python maptool.py
cd..
move .\tiled\output\*.map .\bin\data\
echo.
echo Generating font files...
echo.
cd art
copy original.png font1x.png
magick convert font1x.png -interpolate Nearest -filter point -resize 1024 font2x.png
magick convert font1x.png -interpolate Nearest -filter point -resize 1536 font3x.png
magick convert font1x.png -interpolate Nearest -filter point -resize 2048 font4x.png
magick -size 1024x2 xc:transparent +antialias -stroke rgba(20,12,28,1) -fill rgba(20,12,28,1) -draw "line 0,0 1024,0" scanline2x50.png
magick -size 1536x3 xc:transparent +antialias -stroke rgba(20,12,28,1) -fill rgba(20,12,28,1) -draw "line 0,0 1536,0" scanline3x33.png
magick -size 2048x4 xc:transparent +antialias -stroke rgba(20,12,28,1) -fill rgba(20,12,28,1) -draw "line 0,0 2048,0" scanline4x25.png
magick -size 2048x4 xc:transparent +antialias -stroke rgba(20,12,28,1) -fill rgba(20,12,28,1) -strokewidth 2 -draw "line 0,0 2048,0" scanline4x50.png 
magick composite -tile scanline2x50.png font2x.png font2x_s50.png
magick composite -tile scanline3x33.png font3x.png font3x_s33.png
magick composite -tile scanline4x25.png font4x.png font4x_s25.png
magick composite -tile scanline4x50.png font4x.png font4x_s50.png
del scanline*.png
cd..
move .\art\font*.png .\bin\fonts\