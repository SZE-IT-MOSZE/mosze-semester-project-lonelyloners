#pragma once

#include "headers/Router.h"
#include "headers/RenderWindow.h"
#include "headers/Utils.h"

/**
 * \brief Prologus megjelenítése.
 *
 * Egy képernyőt kap bemeti paraméterként, amire megjelenik a prologus.
 * Visszatérési értékként egy logikai változó szolgál, ami reprezentálja a 
 * a következő döntési ágat.
 * 
 * \param menuWindow az ablak, amire megjelenítjük a menüt.
 * \return menuWindow ami a következő ágat jelöli.
 */

RenderWindow prolog(RenderWindow game, TTF_Font* fnt)
{   
    // fekete háttér prologus 
    SDL_Texture* prolog = game.loadTexture("res/gfx/Dessert_Map1/dessert_map1_betor3.png");
    Entity proolog(V2F(298, 384-17), prolog);
    proolog.setSize(382, 382);
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);
    // beviteli mező háttere
    SDL_Texture* inputTextBckGround = game.loadTexture("res/gfx/Objects/blck_bckgrnd.png");
    Entity inptxtbckground(V2F(0, 384), inputTextBckGround);
    // LyRs összes animációját tartalmazó sprite sheet betöltése
    SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/LyRs/Lyrs_seta.png");
    Entity l(V2F(64, 0), lyrsAnim);
    l.setPosi(64 * game.getRES(), 0);

    // parancs választó deklarálása
    Router r = Router();

    // összes logikai változó a gombnyomásokhoz
    bool gameRunning = true;
    bool attack = false;
    bool fel = false;
    bool le = false;
    bool jobbra = false;
    bool balra = false;
    bool next = false;

    // esemény létrehozása
    SDL_Event event;
    // FPS limitációhoz szükséges változók
    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();
    // input text 
    std::string command;

    SDL_Color blck = {255, 255, 255};

    SDL_Surface* title = TTF_RenderUTF8_Blended(fnt, "PROLOGUS", blck); 
        
    SDL_Texture* Message = SDL_CreateTextureFromSurface(game.getRenderer(), title);

    // létrehoz egy téglalapot
    SDL_Rect Message_rect;
    // beállítja a téglalap x koordinátáját  
    Message_rect.x = 100;
    // beállítja a téglalap x koordinátáját
    Message_rect.y = 50;
    // beállítja a téglalap szélességét
    Message_rect.w = 182;
    // beállítja a téglalap magasságát
    Message_rect.h = 24;

    SDL_StartTextInput();

    // prologus
    while(gameRunning)
    {
        // képkockák számolása
        int startTick = SDL_GetTicks();
        
        float nTime = utils::hireTimeInSeconds();
        float fTime = nTime - cTime;
        
        cTime = nTime;
        accum += fTime;
        // fps limitálása
        while(accum >= timeStep)
        {   
            // események vezérlése
            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    // kilépés gomb lekezelése 
                    case SDL_QUIT:
                        gameRunning = false;
                        break;
                    // szövegbevitel kezelése
                    case SDL_TEXTINPUT:
                        command += event.text.text;
                        break;
                    // gomb lenyomások kezelése                        
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_BACKSPACE:
                                command = command.substr(0, command.size()-1);
                                break;
                            case SDLK_RETURN:
                                if (!fel && !le && !balra && !jobbra && !attack)
                                {
                                    Command c = Command(command);
                                    c.make();
                                    r.route(c.getCommand(), c.getItem(), l);
                                    if (command == "LAPOZZ")
                                    {
                                        game.nextPage();
                                    }
                                    if (command == "POSI")
                                    {
                                        std::cout << " CURRENT POSITION: " << l.getPos().getY() << " \t " << l.getPos().getX() << std::endl;
                                    }
                                    if (command == "TARGET")
                                    {
                                        std::cout << " TARGET COORDINATE: " << l.getTargetY() << " \t " << l.getTargetX() << std::endl;
                                    }
                                    command = "";
                                }
                        }
                }
            }
            accum -= timeStep;
        }           
        const float alpha = accum / timeStep;          

        game.render(inptxtbckground);
        game.renderInputText(command, fnt);
        // szöveg háttér
        game.render(txtbckground);
        gameRunning = game.renderText(fnt);
        SDL_RenderCopy(game.getRenderer(), Message, NULL, &Message_rect);
        // rendererbe tötött elemek képernyőre helyezése
        game.display();
        // TODO:
        // delete c; 
    }
    // memória felszabadítása
    SDL_FreeSurface(title);
    SDL_DestroyTexture(Message);
    game.nextTxt(next);
    return game;
}