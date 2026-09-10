#pragma once
#ifndef NOGDI
#define NOGDI
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>
#include "../../Backend/headerfiles/entities.h"
using namespace std;

class Renderer
{
private:
    Texture2D cardBack;
    Texture2D table;
    Texture2D cardTextures[52];
    Texture2D background;
    Font font;
    Font boldFont;
    Color goldColor;
    Texture2D mute;

public:
    Renderer();
    ~Renderer();
    void drawCardBack(float x, float y);
    void drawTable(int x, int y);
    void drawClock(float currentTime, float totalTime, int x, int y, int radius);
    void drawBackground();
    void drawWholeInterface(Card *hand, int count,int round);
    void drawPlayedCards(std::vector<Move> &moves,int x,int y);
    void drawMute(float x, float y);
    void drawWholeInterface(Card* hand, int count,Rectangle* rects,std::vector<Move> moves,float time,int round);
    void drawWholeInterface(Card* hand, int count, int round, const std::string (&labels)[4]);
    void drawWholeInterface(Card* hand, int count, Rectangle* rects, std::vector<Move> moves, float time, int round, const std::string (&labels)[4]);
    void drawWholeInterface(Card* hand, int count, int round, const std::string (&labels)[4], int currentTurnPlayerId, int localPlayerId);
    void drawWholeInterface(Card* hand, int count, Rectangle* rects, std::vector<Move> moves, float time, int round, const std::string (&labels)[4], int currentTurnPlayerId, int localPlayerId);
    // Also shows each seat's current bid and tricks won, live, during play
    void drawWholeInterface(Card* hand, int count, Rectangle* rects, std::vector<Move> moves, float time, int round, const std::string (&labels)[4], int currentTurnPlayerId, int localPlayerId, const int (&bids)[4], const int (&tricksWon)[4]);
};