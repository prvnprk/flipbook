#include "FileUtils.hpp"
#include "gifr.h"
#include "misc.h"
#include "include/nfd.h"


FileUtils::FileUtils(std::vector<Canvas>& frames) :frames(frames) {}

void FileUtils::save() {
    if (frames.empty()) {
        std::cerr << "No frames to save.\n";
        return;
    }

    NFD_Init();
    nfdu8char_t* outPath;
    nfdu8filteritem_t filters[1] = { { "PXRT", "pxrt" } };
    nfdopendialogu8args_t args = { 0 };
    args.filterList = filters;
    args.filterCount = 1;
    nfdresult_t result = NFD_SaveDialogU8(&outPath,
        args.filterList,
        args.filterCount,
        nullptr,
        nullptr);
    if (result == NFD_OKAY)
    {
        puts("Success!");
        puts(outPath);

    }
    else if (result == NFD_CANCEL)
    {
        puts("User pressed cancel.");
        return;
    }
    else
    {
        printf("Error: %s\n", NFD_GetError());
        return;
    }
    pxrt save;


    save.writepxrt(outPath);
    NFD_FreePathU8(outPath);
    NFD_Quit();
}

void FileUtils::convertToGif(uint32_t scale) {

    if (frames.empty()) {
        std::cerr << "No frames to export.\n";
        return;
    }

    NFD_Init();
    nfdu8char_t* outPath;
    nfdu8filteritem_t filters[1] = { { "GIF", "gif" } };
    nfdopendialogu8args_t args = { 0 };
    args.filterList = filters;
    args.filterCount = 1;
    nfdresult_t result = NFD_SaveDialogU8(&outPath,
        args.filterList,
        args.filterCount,
        nullptr,
        nullptr);
    if (result == NFD_OKAY)
    {
        puts("Success!");
        puts(outPath);

    }
    else if (result == NFD_CANCEL)
    {
        puts("User pressed cancel.");
        return;
    }
    else
    {
        printf("Error: %s\n", NFD_GetError());
        return;
    }


    GifWriter g;


    // if (scale > 1) {
    //
    //     int width = currentState.width * scale;
    //     int height = currentState.height * scale;
    //
    //     GifBegin(&g, outPath, width, height, 0, 8, false, 65534);
    //
    //     for (Canvas& frame : frames) {
    //         sf::Image s = scaleImage(frame.canvasImage, scale);
    //         GifWriteFrame(&g, s.getPixelsPtr(), width, height, frame.frameTime/10);
    //     }
    //
    // }else {
    //
    //
    //     int width = currentState.width;
    //     int height = currentState.height;
    //
    //     std::cout << frames.size();
    //     //GifBegin( int32_t bitDepth = 8, bool dither = false)
    //     GifBegin(&g, outPath, width, height, 0, 8, false, 65534);
    //
    //     //g.t
    //
    //     for (Canvas& frame : frames) {
    //
    //
    //         GifWriteFrame(&g, frame.getCanvasPixelPtr(), width, height, frame.frameTime/10);
    //
    //     }
    //
    //
    // }

    if (scale > 1) {
        int width = currentState.width * scale;
        int height = currentState.height * scale;

        GifBegin(&g, outPath, width, height, 0, 8, false, 65534);

        for (Canvas& frame : frames) {
            sf::Image* s = scaleImageHeap(frame.canvasImage, scale); // heap allocation
            GifWriteFrame(&g, s->getPixelsPtr(), width, height, frame.frameTime / 10);
            delete s; // free heap memory after use
        }
    } else {
        int width = currentState.width;
        int height = currentState.height;

        GifBegin(&g, outPath, width, height, 0, 8, false, 65534);

        for (Canvas& frame : frames) {
            GifWriteFrame(&g, frame.getCanvasPixelPtr(), width, height, frame.frameTime / 10);
        }
    }


    NFD_FreePathU8(outPath);
    GifEnd(&g);
    NFD_Quit();



}


void FileUtils::convertToPng(uint32_t scale) {
    if (frames.empty()) {
        std::cerr << "No frames to export.\n";
        return;
    }

    NFD_Init();
    nfdu8char_t* outPath;
    nfdu8filteritem_t filters[1] = { { "PNG", "png" } };
    nfdopendialogu8args_t args = { 0 };
    args.filterList = filters;
    args.filterCount = 1;
    nfdresult_t result = NFD_SaveDialogU8(&outPath,
        args.filterList,
        args.filterCount,
        nullptr,
        nullptr);
    if (result == NFD_OKAY)
    {
        puts("Success!");
        puts(outPath);

    }
    else if (result == NFD_CANCEL)
    {
        puts("User pressed cancel.");
        return;
    }
    else
    {
        printf("Error: %s\n", NFD_GetError());
        return;
    }

    if (scale > 1) {

        sf::Image s = scaleImage(currentState.canvas->canvasImage, scale);
        s.saveToFile(outPath);

    }
    else {
        currentState.canvas->exportCanvasImage(outPath);

    }






    NFD_FreePathU8(outPath);
    NFD_Quit();




}


std::string FileUtils::open() {
    NFD_Init();

    nfdu8char_t* outPath;
    nfdu8filteritem_t filters[1] = { { "PXRT", "pxrt" } };
    nfdopendialogu8args_t args = { 0 };
    args.filterList = filters;
    args.filterCount = 1;
    nfdresult_t result = NFD_OpenDialogU8_With(&outPath, &args);

    std::string outpath;

    if (result == NFD_OKAY)
    {
        puts("Success!");
        outpath = outPath;
        puts(outPath);

    }
    else if (result == NFD_CANCEL)
    {
        puts("User pressed cancel.");

        return "0";
    }
    else
    {
        printf("Error: %s\n", NFD_GetError());

        return "0";
    }

    NFD_FreePathU8(outPath);
    NFD_Quit();
    return outpath;
}



