#include "headers/RenderPlanets.h"
#include "headers/Entity.h"
#include "headers/LoadPlanet.h"
#include "headers/Command.h"
#include "headers/Plnt.h"
#include "headers/Router.h"
#include "headers/Utils.h"

Plnt::Plnt(RenderWindow g, TTF_Font* f) : game(g), fnt(f)
{
    // LyRs üresjárati animációjának a piozíciói
    // jobb            
    lyrsIdleR       = { { 0,   0}, {64,   0}, {128,   0}, {192,   0} };
    // bal
    lyrsIdleL       = { {32,  32}, {96,  32}, {160,  32}, {224,  32} };
    
    // LyRs séta animációjának a piozíciói
    // jobb
    lyrsMoveR       = { { 0,  64}, {64,  64}, {128,  64}, {192,  64}, {256,  64} };
    // bal
    lyrsMoveL       = { {32,  96}, {96,  96}, {160,  96}, {224,  96}, {290,  96} };
    
    // LyRs lövés animációjának a piozíciói
    // jobb
    lyrsLaserR      = { { 0, 128}, {64, 128}, {128, 128}, {192, 128}, {256, 128} , 
                        { 0, 160}, {64, 160}, {128, 160}, {192, 160}, {256, 160} , 
                        { 0, 192}, {64, 192}, {128, 192}, {192, 192}, {256, 192} ,
                        { 0, 224}, {64, 224}, {128, 224}, {192, 224}, {256, 224} };
    // bal
    lyrsLaserL      = { { 0, 256}, {64, 256}, {128, 256}, {192, 256}, {256, 256} , 
                        { 0, 288}, {64, 288}, {128, 288}, {192, 288}, {256, 288} , 
                        { 0, 320}, {64, 320}, {128, 320}, {192, 320}, {256, 320} ,
                        { 0, 352}, {64, 352}, {128, 352}, {192, 352}, {256, 352} };

}
/**
 * \brief Menü megjelenítése.
 *
 */
int Plnt::menu()
{
    int selectednumber;
    bool menu = true;
    std::string input;
    int c,i=0;
    char str[100];
    int res = game.getRES();

    SDL_Texture* newGame = nullptr;
    // háttér betöltése
    SDL_Texture* mnuBckGround = game.loadTexture("res/gfx/Menu/menu_hatter.png");
    Entity bckground(V2F(0, 0), mnuBckGround);
    
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);

    // nagy új játék gomb
    SDL_Texture* newGameButton = game.loadTexture("res/gfx/Menu/menu_alap_nagy_ujjatek.png");
    Entity nGameB(V2F(30, 20), newGameButton);
    nGameB.setSize(125,65);

    // nagy új játék gomb lenyomott
    SDL_Texture* newGameButtonDown = game.loadTexture("res/gfx/Menu/menu_alap_nagy_benyomott_ujjatek.png");
    Entity nGameBD(V2F(30 /* * getR() */, 20 /* * getR() */), newGameButtonDown);
    nGameBD.setSize(125,65);

    // betöltés gomb
    SDL_Texture* loadGameButton = game.loadTexture("res/gfx/Menu/menu_alap_betoltes.png");
    Entity lgGameB(V2F(35, 116), loadGameButton);
    lgGameB.setSize(95,43);

    // betöltés gomb lenyomott
    SDL_Texture* loadGameButtonDown = game.loadTexture("res/gfx/Menu/menu_alap_benyomott_betoltes.png");
    Entity lgGameBD(V2F(35, 116), loadGameButtonDown);
    lgGameBD.setSize(95,43);

    // segítség gomb    
    SDL_Texture* helpGameButton = game.loadTexture("res/gfx/Menu/menu_alap_segitseg.png");
    Entity hlpGameB(V2F(35, 189), helpGameButton);
    hlpGameB.setSize(95,43);

    // segítség gomb lenyomott
    SDL_Texture* helpGameButtonDown = game.loadTexture("res/gfx/Menu/menu_alap_benyomott_segitseg.png");
    Entity hlpGameBD(V2F(35, 189), helpGameButtonDown);
    hlpGameBD.setSize(95,43);

    // beállítások gomb
    SDL_Texture* setGameButton = game.loadTexture("res/gfx/Menu/menu_alap_beallitas.png");
    Entity setGameB(V2F(385 - 35 - 95, 116), setGameButton);
    setGameB.setSize(95,43);

    // beállítások gomb lenyomott
    SDL_Texture* setGameButtonDown = game.loadTexture("res/gfx/Menu/menu_alap_benyomott_beallitas.png");
    Entity setGameBD(V2F(384 - 35 - 95, 116), setGameButtonDown);
    setGameBD.setSize(95,43);

    // kilépés gomb
    SDL_Texture* exitGameButton = game.loadTexture("res/gfx/Menu/menu_alap_kilepes.png");
    Entity eGameB(V2F(385 - 35 - 95, 189), exitGameButton);
    eGameB.setSize(95,43);

    // kilépés gomb lenyomott
    SDL_Texture* exitGameButtonDown = game.loadTexture("res/gfx/Menu/menu_alap_benyomott_kilepes.png");
    Entity eGameBD(V2F(384 - 35 - 95, 189), exitGameButtonDown);
    eGameBD.setSize(95,43);
    // fő ciklus változó
    bool menuRunning = true;

    newGame = newGameButton;
    // event létrehozás a menü ciklushoz
    SDL_Event event;

    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();
    // fő menü ciklus
    while(menuRunning)
    {
        // képkocka idők számolás    
        int startTick = SDL_GetTicks();

        float nTime = utils::hireTimeInSeconds();
        float fTime = nTime - cTime;

        cTime = nTime;
        accum += fTime;
        // logikai változók a gombokhoz
        bool nGameDown = false;
        bool eGameDown = false;
        bool lgGameDown = false;
        bool hlpGameDown = false;
        bool setGameDown = false;
       
        while(accum >= timeStep)
        {
            // események vezérlése
            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                    {
                        if (event.button.button = SDL_BUTTON_LEFT)
                        {
                            // új játék gomb lenyomásának ellenőrzése
                            if (
                                event.button.x > 30 * res
                            and event.button.x < 30 * res + 125 * res
                            and event.button.y > 20 * res 
                            and event.button.y < (20 + 65) * res
                            ) 
                            {
                                nGameDown = true;
                            }
                            // betöltés gomb lenyomásának ellenőrzése
                            else if (
                                event.button.x > 35 * res
                            and event.button.x < 35 * res + 95 * res
                            and event.button.y > 116 * res 
                            and event.button.y < 116 * res + 35 * res
                            ) 
                            {
                                lgGameDown = true;
                            }
                            // segítség gomb lenyomásának ellenőrzése
                            else if (
                                event.button.x > 35 * res 
                            and event.button.x < 35 * res + 95 /* * getR() */  
                            and event.button.y > 189 * res  
                            and event.button.y < 189 * res + 35 /* * getR() */
                            ) 
                            {
                                hlpGameDown = true;
                            }   
                            // beállítások gomb lenyomásának ellenőrzése
                            else if (
                                event.button.x > 384 * res - 35 * res - 95 * res
                            and event.button.x < 384 * res - 35 * res
                            and event.button.y > 116 * res 
                            and event.button.y < 116 * res + 35 * res
                            ) 
                            {
                                setGameDown = true;
                            }
                            // kilépés gomb lenyomásának ellenőrzése
                            else if (
                                event.button.x > 384 * res - 35 * res - 95 * res
                            and event.button.x < 384 * res - 35 * res
                            and event.button.y > 189 * res 
                            and event.button.y < 189 * res + 35 * res
                            ) 
                            {
                                eGameDown = true;
                            }
                        }
                    }
                }
             }
            accum -= timeStep;  
        }

        const float alpha = accum / timeStep;       
        if ( nGameDown )
        {
            game.render(nGameBD);
            selectednumber = 1;
            game.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        else if (lgGameDown)
        {
            game.render(lgGameBD);
            selectednumber = 2;
            game.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        else if (hlpGameDown)
        {
            game.render(hlpGameBD);
            selectednumber = 3;
            game.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        else if (setGameDown)
        {
            game.render(setGameBD);
            selectednumber = 4;
            game.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        else if (eGameDown)
        {
            game.render(eGameBD);
            selectednumber = 5;
            game.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        if (hlpGameDown == true)
        {
            
        }
        // gombok megjelenítése
        game.render(bckground);  
        game.render(txtbckground); 
        game.renderText(fnt);
        game.render(nGameB);
        game.render(lgGameB);
        game.render(hlpGameB);
        game.render(setGameB);  
        game.render(eGameB);  
        game.display();
    }
    game.nextTxt(false);

    return selectednumber;
}
/**
 * \brief Prologus megjelenítése.
 *
 */
void Plnt::prolog()
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
    SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/LyRs/lyrs_sprite_sheet.png");
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
    Command c = Command();

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
                                    c.make(command);
                                    r.route(c.getCommand(), c.getItem(), l);
                                    c.reset();

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
}
/**
 * \brief Dessert pálya felszín megjelenítése.
 *
 */

void Plnt::dessert1()
{      
    // LyRs összes animációját tartalmazó sprite sheet betöltése
    SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/LyRs/lyrs_sprite_sheet.png");
    Entity l(V2F(64, 0), lyrsAnim);
    l.setPosi(64 * game.getRES(), 0);
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);
    // beviteli mező háttere
    SDL_Texture* inputTextBckGround = game.loadTexture("res/gfx/Objects/blck_bckgrnd.png");
    Entity inptxtbckground(V2F(0, 384), inputTextBckGround);

    // Entity vector létrehozása
    std::vector<Entity> planet1 = {};
    planet1 = LoadPlanet(game, "res/gfx/Dessert_Map1/dessert_map1_felho.png");
    // logikai változókat tartalmazó vektor definiálása
    std::vector<bool> planetR = {};
    planetR = setPlanetPos();

    // első térkép hátterének betöltése
    SDL_Texture* background = game.loadTexture("res/gfx/Dessert_Map1/dessert_map1_alapmap.png");
    Entity pl(V2F(0, 0), background);
    // ajtó
    SDL_Texture* door = game.loadTexture("res/gfx/Dessert_Map1/dessert_map1_betor0.png");
    Entity dooor(V2F(306, 384 - 17), door);
    dooor.setSize(18,17);
    // ajtó betörés közben 
    SDL_Texture* bdoor = game.loadTexture("res/gfx/Dessert_Map1/dessert_map1_betor2.png");
    Entity bdooor(V2F(298, 384-17), bdoor);
    bdooor.setSize(35, 20);
    // ajtó betört 
    SDL_Texture* cdoor = game.loadTexture("res/gfx/Dessert_Map1/dessert_map1_betor3.png");
    Entity cdooor(V2F(298, 384-17), cdoor);
    cdooor.setSize(35, 20);

    // parancs választó deklarálása
    Router r = Router();

    // összes logikai változó a gombnyomásokhoz
    bool gameRunning = true;
    bool attack = false;
    bool fel = false;
    bool le = false;
    bool jobbra = false;
    bool balra = false;
    bool flip = true;
    bool crack = false;
    bool nxttxt = false;
    bool csakegyszer = false;
    // esemény létrehozása
    SDL_Event event;
    // FPS limitációhoz szükséges változók
    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();
    // input text 
    std::string command;
    
    Command c = Command();

    gameRunning = true;
    // dessert1
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
                                if (command == "LAPOZZ")
                                {
                                    game.nextPage();
                                }
                                if (command == "TAMADAS")
                                {
                                    attack = true;
                                }
                                if (command == "POSI")
                                {
                                    std::cout << " CURRENT POSITION: " << l.getPos().getY() << " \t " << l.getPos().getX() << std::endl;
                                }
                                if (command == "TARGET")
                                {
                                    std::cout << " TARGET COORDINATE: " << l.getTargetY() << " \t " << l.getTargetX() << std::endl;
                                }
                                if (command == "BELEP" && crack)
                                {
                                    gameRunning = false;
                                }
                                c.make(command);
                                r.route(c.getCommand(), c.getItem(), l);
                                c.reset();
                                
                                command = "";
                            }
                        }
                }
            }
            accum -= timeStep;
        }           
        const float alpha = accum / timeStep;          
        // irányok beállítása
        switch (l.getDirection())
        {
            case 0:
                break;
            case 1:
                // fel
                fel = true;
                break;
            case 2:
                // jobbra
                jobbra = true;
                break;     
            case 3:
                // le
                le = true;
                break;
            case 4: 
                // balra
                balra = true;
                break;
            default:
                break;
        }
        
        // először a háttér kirajzolása
        game.render(pl);
        // ajtó kirenderelése megfelelő állapot szerint
        if (!crack) 
        {
            game.render(dooor);
        }
        else if (crack && attack)
        {
            game.render(bdooor);
        }
        else
        {
            game.render(cdooor);
        }
        if (!fel && !le && !balra && !jobbra && !attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleR, lyrsIdleR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleL, lyrsIdleL.size(), 32, 32, 0, true);
            }
            // if (l.getPos().getX() != l.getTargetX() || l.getPos().getY() != l.getTargetY())
            // {
            //     l.setPosi(l.getPos().getX(), l.getPos().getY());
            // } 
        }
        // felfele gomb megnyomva?
        if (fel && !attack)
        {                
            if (l.getPos().getY() <= l.getTargetY())
            {
                fel = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása fel
                game.up(l);
            }

            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // lefele gomb megnyomva?
        if (le && !attack)
        {
            if (l.getPos().getY() >= l.getTargetY())
            {
                le = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása le
                game.down(l);
            }
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // balra gomb megnyomva?
        if (balra && !attack)
        {
            if (l.getPos().getX() <= l.getTargetX())
            {
                balra = false;
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása balra
                game.left(l);
            }
            // LyRs balra mozog animáció következő kockája
            game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            // összes animáció balra néz
            flip = false;
        }
        // jobbra gomb megnyomva?
        if (jobbra && !attack)
        {
            if (l.getPos().getX() >= l.getTargetX())
            {
                jobbra = false;
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása jobbra
                game.right(l);
            }
            // LyRs jobbra mozog animáció következő kockája
            game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            // összes animáció jobbra néz
            flip = true;
        }
        // szóköz gomb megnyomva?
        if (attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra támad animáció következő kockája
                attack = game.update(l, lyrsLaserR, lyrsLaserR.size(), 64, 32, 0, false);
            }
            else
            {
                // LyRs balra támad animáció következő kockája
                attack = game.update(l, lyrsLaserL, lyrsLaserL.size(), 64, 32, 32, false);
            }
            if ((l.getPos().getY() == 352 && l.getPos().getX() == 288) || (l.getPos().getY() == 352 && l.getPos().getX() == 320))
            {
                crack = true;
            }
        }
        if (crack)
        {
            if (!csakegyszer)
            {
                game.nextTxt(false);
                game.resetPage();
                csakegyszer = true;
            }
        }
        // felhők renderelése és ütközések ellenőrzése és lekezelése
        planetR = renderPlanet(game, planet1, planetR, l);
        game.render(inptxtbckground);
        game.renderInputText(command, fnt);
        // szöveg háttér
        game.render(txtbckground);
        game.renderText(fnt);
        // rendererbe tötött elemek képernyőre helyezése
        game.display();
        // TODO:
        // delete c; 
    }
    game.clear();
}
/**
 * \brief Dessert pálya föld alatti részének megjelenítése.
 *
 */
void Plnt::dessert2()
{  
    // egész számokból álló párokból álló vektorok definiálása
    std::vector<std::pair<int, int>> npcIdleR;
    std::vector<std::pair<int, int>> npcIdleL;
    std::vector<std::pair<int, int>> latnokMoveR;
    std::vector<std::pair<int, int>> latnokMoveL;
    std::vector<std::pair<int, int>> antMoveR;
    std::vector<std::pair<int, int>> antMoveL;
    std::vector<std::pair<int, int>> urgeIdleL;
    std::vector<std::pair<int, int>> urgeIdleR;
    std::vector<std::pair<int, int>> urgeAttackL;
    std::vector<std::pair<int, int>> urgeAttackR;
    std::vector<std::pair<int, int>> nagyonIdleR;
    std::vector<std::pair<int, int>> nagyonIdleL;

    std::vector<std::pair<int, int>> map;

    // Látnokond üresjárati
    // jobb
    npcIdleR = { { 0,   0}, {32,   0}};
    // bal
    npcIdleL = { { 64,   0}, {96,  0}};

    // látnokondokok séta animációjának a pozíciói
    // jobb
    latnokMoveR = { {  0,   0}, { 32,   0}, { 64,   0}, { 96,  0},  {128,  0} };
    // bal
    latnokMoveL = { {160,   0}, {192,   0}, {224,   0}, {256,  0},  {288,  0} };

    // hangya séta animációjának a pozíciói
    // jobb
    antMoveR = { {  0,   0}, { 32,   0}, { 64,   0}, { 96,  0} };
    // bal
    antMoveL = { {128,  0}, {160,   0}, {192,   0}, {224,   0} };

    // urge üresjárati 
    // jobb
    urgeIdleR = { {  0,   0}, { 32,   0}, { 64,   0}, { 96,  0},  {128,  0},  {160,  0},  {192,  0},  {224,  0},  {256,  0},  {288,  0} };
    // bal
    urgeIdleL = { {320,   0}, {352,   0}, {384,   0}, {416,  0},  {448,  0},  {480,  0},  {512,  0},  {544,  0},  {576,  0},  {608,  0} };
    
    // urge támadás 
    // jobb
    urgeAttackR = { {  0,   0}, { 64,   0},  {128,  0}, {192,  0},  {256,  0},  {320,  0},  {384,  0},  {448,  0} };
    // bal
    urgeAttackL = { {512,   0}, {576,   0}, {640,   0}, {704,  0},  {768,  0},  {832,  0},  {896,  0},  {960,  0} };

    // NAGYON kígyó üresjárati 
    // jobb
    nagyonIdleR = { {  0,  0}, { 32,  0}, { 64,   0}, { 96,  0}, {128,  0}, {160,  0},  {192,  0},  {224,  0} };
    // bal
    nagyonIdleL = { {256,  0}, {288,  0}, {320,   0}, {352,  0}, {384,  0}, {416,  0},  {448,  0},  {480,  0} };

    // map
    map             = { {  0,   0}, {384,   0},
                        {  0, 384}, {384, 384}};

    // LyRs összes animációját tartalmazó sprite sheet betöltése
    SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/LyRs/lyrs_sprite_sheet.png");
    Entity l(V2F(288, 32), lyrsAnim);
    l.setPosi(288 * game.getRES(), 32 * game.getRES());
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);
    // beviteli mező háttere
    SDL_Texture* inputTextBckGround = game.loadTexture("res/gfx/Objects/blck_bckgrnd.png");
    Entity inptxtbckground(V2F(0, 384), inputTextBckGround);
    // első térkép hátterének betöltése
    SDL_Texture* background = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2.png");
    Entity pl(V2F(0, 0), background);
    // látnokondokok betöltése
    SDL_Texture* latnok1        = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_man_grey_idle.png");
    SDL_Texture* latnok2        = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_man_green_idle.png");
    SDL_Texture* latnok3        = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_man_brown_idle.png");
    SDL_Texture* latnok4        = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_man_blue_idle.png");
    SDL_Texture* latnok5        = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_wollaris_idle.png");
    SDL_Texture* latnok6        = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_woman_pink_idle.png");
    SDL_Texture* latnokMereg    = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_mergezett_idle.png");

    SDL_Texture* latnok1a       = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_man_grey_seta.png");
    SDL_Texture* latnok2a       = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_man_green_seta.png");
    SDL_Texture* latnok3a       = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_man_brown_seta.png");
    SDL_Texture* latnok4a       = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_man_blue_seta.png");
    SDL_Texture* latnok5a       = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_wollaris_seta.png");
    SDL_Texture* latnok6a       = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_woman_pink_seta.png");
    SDL_Texture* latnokMerega   = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_latnokondok_mergezett_seta.png");

    SDL_Texture* wtr = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2_water.png");
    Entity wtrE(V2F(272, 305), wtr);
    wtrE.setSize(87, 60);
    // ládák betöltése
    SDL_Texture* chst = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2_chest.png");
    Entity chstE(V2F(224, 116), chst);
    chstE.setSize(120, 50);
    
    SDL_Texture* chst2 = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2_chest.png");
    Entity chst2E(V2F(234, 244), chst2);
    chst2E.setSize(120, 50);

    Entity latnok1E(V2F(0,0), latnok1);
    Entity latnok2E(V2F(0,0), latnok2);
    Entity latnok3E(V2F(0,0), latnok3);
    Entity latnok4E(V2F(0, 0), latnok4);
    Entity latnok5E(V2F(192, 96), latnok5);
    Entity latnok6E(V2F(96, 352), latnok6);
    Entity latnokMeregE(V2F(160, 128), latnokMereg);

    Entity latnok1Ea(V2F(0, 0), latnok1a);
    Entity latnok2Ea(V2F(0, 0), latnok2a);
    Entity latnok3Ea(V2F(0, 0), latnok3a);
    Entity latnok4Ea(V2F(0, 0), latnok4a);
    Entity latnok5Ea(V2F(192, 96), latnok5a);
    Entity latnok6Ea(V2F(96, 352), latnok6a);
    Entity latnokMeregEa(V2F(160, 128), latnokMerega);

    latnok1Ea.setPosi(-32, 96);
    latnok2Ea.setPosi(-64, 96);
    latnok3Ea.setPosi(-96, 96);
    
    latnok1E.setPosi(64, 96);
    latnok2E.setPosi(96, 96);
    latnok3E.setPosi(128, 96);
    // hangyák betöltése
    SDL_Texture* antI1 = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_hangya_idle.png");
    Entity antEI1(V2F(0,0), antI1);
    antEI1.setPosi(192, 96);
    SDL_Texture* antI2 = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_hangya_idle.png");
    Entity antEI2(V2F(0,0), antI2);
    antEI2.setPosi(224, 96);
    SDL_Texture* antI3 = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_hangya_idle.png");
    Entity antEI3(V2F(0,0), antI3);
    antEI3.setPosi(320, 96);
    SDL_Texture* antA = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_hangya_seta.png");
    Entity antEA(V2F(0,0), antA);
    
    // urge
    SDL_Texture* urge1 = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_urge_idle.png");
    Entity urgeE1(V2F(0,0), urge1);
    urgeE1.setPosi(192, 320);
    SDL_Texture* urge2 = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_urge_idle.png");
    Entity urgeE2(V2F(0,0), urge2);
    urgeE2.setPosi(224, 320);
    
    // sivatagi bogyeszok
    SDL_Texture* bogyesz1 = game.loadTexture("res/gfx/Objects/dessert_map2_sivatagibogyo.png");
    Entity bogyesz1E(V2F(232, 80), bogyesz1);
    bogyesz1E.setSize(16, 16);
    SDL_Texture* bogyesz2 = game.loadTexture("res/gfx/Objects/dessert_map2_sivatagibogyo.png");
    Entity bogyesz2E(V2F(72, 48), bogyesz2);
    bogyesz2E.setSize(16, 16);
    SDL_Texture* bogyesz3 = game.loadTexture("res/gfx/Objects/dessert_map2_sivatagibogyo.png");
    Entity bogyesz3E(V2F(168, 112), bogyesz3);
    bogyesz3E.setSize(16, 16);
    SDL_Texture* bogyesz4 = game.loadTexture("res/gfx/Objects/dessert_map2_sivatagibogyo.png");
    Entity bogyesz4E(V2F(104, 176), bogyesz4);
    bogyesz4E.setSize(16, 16);

    // NAGYON kígyó betöltése 
    SDL_Texture* jujjEzNagyonKigyo1 = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_kigyo_idle.png");
    Entity jujjEzNagyonKigyoE1(V2F(0,0), jujjEzNagyonKigyo1);
    jujjEzNagyonKigyoE1.setPosi(224, 288);
    SDL_Texture* jujjEzNagyonKigyo2 = game.loadTexture("res/gfx/Animations/Dessert_bolygo/dessert_kigyo_idle.png");
    Entity jujjEzNagyonKigyoE2(V2F(0,0), jujjEzNagyonKigyo2);
    jujjEzNagyonKigyoE2.setPosi(320, 288);

    // térbeli kövek
    SDL_Texture* rocks = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2_rocks.png");
    Entity rocksEntity(V2F(0, 0), rocks);

    // Entity vector létrehozása
    std::vector<Entity> planet1 = {};
    planet1 = LoadPlanet(game, "res/gfx/Dessert_Map2/dessert_map2_felho.png");
    // logikai változókat tartalmazó vektorok definiálása
    std::vector<bool> planetR1 = {};
    planetR1 = setPlanetPos();

    std::vector<bool> planetR2 = {};
    planetR2 = setPlanetPos();

    std::vector<bool> planetR3 = {};
    planetR3 = setPlanetPos();

    std::vector<bool> planetR4 = {};
    planetR4 = setPlanetPos();


    // parancs választó deklarálása
    Router r = Router();

    int lat1 = 0;    
    int lat2 = 0;    
    int lat3 = 0;

    // összes logikai változó 
    bool gameRunning = true;
    bool attack = false;
    bool fel = false;
    bool le = false;
    bool jobbra = false;
    bool balra = false;
    bool flip = false;
    bool beszel = false;
    bool belep = false;
    bool next = false;
    bool a = false;
    bool b = false;
    bool start = false;
    bool dontA = false;
    bool dontB = false;
    bool csakegyszer = false;
    bool kamraIndul = false;
    bool d = false;

    // esemény létrehozása
    SDL_Event event;
    // FPS limitációhoz szükséges változók
    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();
    // input text 
    std::string command;
    
    game.nextTxt(next);

    Command c = Command();

    gameRunning = true;
    // dessert1
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
                                if (command == "LAPOZZ")
                                {
                                    game.nextPage();
                                }
                                if (command == "DONT A")
                                {
                                    dontA = true;
                                }
                                else if (command == "DONT B")
                                {
                                    dontB = true;
                                }
                                if (command == "TAMADAS")
                                {
                                    attack = true;
                                }
                                if (command == "POSI")
                                {
                                    std::cout << " CURRENT POSITION: " << l.getPos().getY() << " \t " << l.getPos().getX() << std::endl;
                                }
                                if (command == "TARGET")
                                {
                                    std::cout << " TARGET COORDINATE: " << l.getTargetY() << " \t " << l.getTargetX() << std::endl;
                                }
                                if (command == "BELEP")
                                {
                                    belep = true;
                                }
                                if (command == "BESZEL")
                                {
                                    beszel = true;
                                }
                                c.make(command);
                                r.route(c.getCommand(), c.getItem(), l);
                                c.reset();

                                command = "";
                            }
                        }
                }
            }
            accum -= timeStep;
        }           
        const float alpha = accum / timeStep;    

        // megfelelő map kirenderelése
        if (game.getMap() == 0 && l.getPos().getY() == 320 && l.getPos().getX() >= 384)
        {
            // MAP 1 -> MAP 2
            game.setMap(1);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }
        else if (game.getMap() == 1 && l.getPos().getY() == 320 && l.getPos().getX() <= -32)
        {
            // MAP 2 -> MAP 1
            game.setMap(0);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY()  >= 384 && l.getPos().getX() == 32)
        {
            // MAP 1 -> MAP 3
            game.setMap(2);

            l.setPosi(0, -416);

            l.setTarget(3, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() == -32 && l.getPos().getX() == 32)
        {
            // MAP 3 -> MAP 1
            game.setMap(0);

            l.setPosi(0, 416);

            l.setTarget(1, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY()  >= 384 && l.getPos().getX() == 128)
        {
            // MAP 1 -> MAP 3
            game.setMap(2);

            l.setPosi(0, -416);

            l.setTarget(3, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() == -32 && l.getPos().getX() == 128)
        {
            // MAP 3 -> MAP 1
            game.setMap(0);

            l.setPosi(0, 416);

            l.setTarget(1, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() == 64 && l.getPos().getX() >= 384)
        {
            // MAP 3 -> MAP 4
            game.setMap(3);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }
        else if (game.getMap() == 3 && l.getPos().getY() == 64 && l.getPos().getX() <= -32)
        {
            // MAP 4 -> MAP 3
            game.setMap(2);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }

        // irányok beállítása
        switch (l.getDirection())
        {
        case 0:
            break;
        case 1:
            // fel
            fel = true;
            break;
        case 2:
            // jobbra
            jobbra = true;
            break;     
        case 3:
            // le
            le = true;
            break;
        case 4: 
            // balra
            balra = true;
            break;
        case 5:
            attack = true;
        default:
            break;
        }
        // először a háttér kirajzolása
        game.updateMap(pl, map);

        if (!fel && !le && !balra && !jobbra && !attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleR, lyrsIdleR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleL, lyrsIdleL.size(), 32, 32, 0, true);
            }
            // if (l.getPos().getX() != l.getTargetX() || l.getPos().getY() != l.getTargetY())
            // {
            //     l.setPosi(l.getPos().getX(), l.getPos().getY());
            // } 
        }
        // felfele gomb megnyomva?
        if (fel && !attack)
        {                
            if (l.getPos().getY() <= l.getTargetY())
            {
                fel = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása fel
                game.up(l);
            }

            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // lefele gomb megnyomva?
        if (le && !attack)
        {
            if (l.getPos().getY() >= l.getTargetY())
            {
                le = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása le
                game.down(l);
            }
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // balra gomb megnyomva?
        if (balra && !attack)
        {
            if (l.getPos().getX() <= l.getTargetX())
            {
                balra = false;
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása balra
                game.left(l);
            }
            // LyRs balra mozog animáció következő kockája
            game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            // összes animáció balra néz
            flip = false;
        }
        // jobbra gomb megnyomva?
        if (jobbra && !attack)
        {
            if (l.getPos().getX() >= l.getTargetX())
            {
                jobbra = false;
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása jobbra
                game.right(l);
            }
            // LyRs jobbra mozog animáció következő kockája
            game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            // összes animáció jobbra néz
            flip = true;
        }
        // szóköz gomb megnyomva?
        if (attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra támad animáció következő kockája
                attack = game.update(l, lyrsLaserR, lyrsLaserR.size(), 64, 32, 0, false);
            }
            else
            {
                // LyRs balra támad animáció következő kockája
                attack = game.update(l, lyrsLaserL, lyrsLaserL.size(), 64, 32, 32, false);
            }
        }
        if (l.getPos().getY() == 256 && l.getPos().getX() == 32 && belep) 
        {
            gameRunning = false;
        }
        switch (game.getMap())  {
            case 0:
                game.update(latnok5E, npcIdleL, npcIdleL.size(), 32, 32, 0, true);
                game.update(latnok6E, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                if (l.getPos().getX() == 160 && l.getPos().getY() == 96 && beszel)
                {
                    if (!a)
                    {
                        game.nextTxt(false);
                        a = true;
                    }
                    if (game.getPage() == 7 && !b)
                    {
                        start = true;
                        b = true;
                    }
                }
                if (start && !kamraIndul)
                {
                    if (latnok1Ea.getPos().getX() < 65)
                    {
                        game.right(latnok1Ea);
                        game.update(latnok1Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                    }
                    else 
                    {                        
                        game.update(latnok1E, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                    }
                    if (latnok2Ea.getPos().getX() < 97)
                    {
                        game.right(latnok2Ea);
                        game.update(latnok2Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                    }
                    else
                    {                        
                        game.update(latnok2E, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                    }
                    if (latnok3Ea.getPos().getX() < 129)
                    {
                        game.right(latnok3Ea);
                        game.update(latnok3Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                    }
                    else
                    {                        
                        game.update(latnok3E, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                    }
                }
                if (l.getPos().getY() == 96 && l.getPos().getX() == 160)
                {
                    if (dontA)
                    {   
                        if (!csakegyszer)
                        {
                            game.nextTxt(true);
                            csakegyszer = true;
                        }
                        if (game.getPage() == 7)
                        {
                            kamraIndul = true;     
                        }   
                    }
                    else if (dontB)
                    {
                        if (!csakegyszer)
                        {
                            game.nextTxt(false);
                            csakegyszer = true;
                        }
                        if (game.getPage() == 7)
                        {
                            kamraIndul = true;     
                        }   

                    }
                }
                if (kamraIndul)   
                {
                    if (latnok1Ea.getPos().getY() == 96 && latnok1Ea.getPos().getX() == 320)
                    {                        
                        lat1++;
                    }
                    if (latnok1Ea.getPos().getY() == 160 && latnok1Ea.getPos().getX() == 320)
                    {                        
                        lat1++;
                    }
                    if (latnok1Ea.getPos().getY() == 160 && latnok1Ea.getPos().getX() == 160)
                    {                        
                        lat1++;
                    }
                    if (latnok1Ea.getPos().getY() == 224 && latnok1Ea.getPos().getX() == 160)
                    {                        
                        lat1++;
                    }
                    if (latnok1Ea.getPos().getY() == 224 && latnok1Ea.getPos().getX() == 224)
                    {                        
                        lat1++;
                    }
                    if (latnok1Ea.getPos().getY() == 256 && latnok1Ea.getPos().getX() == 224)
                    {                        
                        lat1++;
                    }                   
                    if (latnok1Ea.getPos().getY() == 256 && latnok1Ea.getPos().getX() == 256)
                    {                        
                        lat1 = 7;
                    }
                    switch (lat1)
                    {
                        case 0:
                            game.right(latnok1Ea);
                            game.update(latnok1Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 1:
                            game.down(latnok1Ea);
                            game.update(latnok1Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 2:
                            game.left(latnok1Ea);
                            game.update(latnok1Ea, latnokMoveL, latnokMoveL.size(), 32, 32, 0, true);
                            break;
                        case 3:
                            game.down(latnok1Ea);
                            game.update(latnok1Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 4:
                            game.right(latnok1Ea);
                            game.update(latnok1Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 5:
                            game.down(latnok1Ea);
                            game.update(latnok1Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);                            
                            break;
                        case 6:
                            game.right(latnok1Ea);
                            game.update(latnok1Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 7:
                            latnok1E.setAbsPosi(256, 256);
                            game.update(latnok1E, npcIdleL, npcIdleL.size(), 32, 32, 0, true);
                            break;
                    }
                    if (latnok2Ea.getPos().getY() == 96 && latnok2Ea.getPos().getX() == 320)
                    {                        
                        lat2++;
                    }
                    if (latnok2Ea.getPos().getY() == 160 && latnok2Ea.getPos().getX() == 320)
                    {                        
                        lat2++;
                    }
                    if (latnok2Ea.getPos().getY() == 160 && latnok2Ea.getPos().getX() == 160)
                    {                        
                        lat2++;
                    }
                    if (latnok2Ea.getPos().getY() == 224 && latnok2Ea.getPos().getX() == 160)
                    {                        
                        lat2++;
                    }
                    if (latnok2Ea.getPos().getY() == 224 && latnok2Ea.getPos().getX() == 224)
                    {                        
                        lat2++;
                    }
                    if (latnok2Ea.getPos().getY() == 256 && latnok2Ea.getPos().getX() == 224)
                    {                        
                        lat2++;
                    }                   
                    if (latnok2Ea.getPos().getY() == 256 && latnok2Ea.getPos().getX() == 288)
                    {                        
                        lat2 = 7;
                    }
                    switch (lat2)
                    {
                        case 0:
                            game.right(latnok2Ea);
                            game.update(latnok2Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 1:
                            game.down(latnok2Ea);
                            game.update(latnok2Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 2:
                            game.left(latnok2Ea);
                            game.update(latnok2Ea, latnokMoveL, latnokMoveL.size(), 32, 32, 0, true);
                            break;
                        case 3:
                            game.down(latnok2Ea);
                            game.update(latnok2Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 4:
                            game.right(latnok2Ea);
                            game.update(latnok2Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 5:
                            game.down(latnok2Ea);
                            game.update(latnok2Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);                            
                            break;
                        case 6:
                            game.right(latnok2Ea);
                            game.update(latnok2Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 7:
                            latnok2E.setAbsPosi(288, 256);
                            game.update(latnok2E, npcIdleL, npcIdleL.size(), 32, 32, 0, true);
                            break;
                    }
                    if (latnok3Ea.getPos().getY() == 96 && latnok3Ea.getPos().getX() == 320)
                    {                        
                        lat3++;
                    }
                    if (latnok3Ea.getPos().getY() == 160 && latnok3Ea.getPos().getX() == 320)
                    {                        
                        lat3++;
                    }
                    if (latnok3Ea.getPos().getY() == 160 && latnok3Ea.getPos().getX() == 160)
                    {                        
                        lat3++;
                    }
                    if (latnok3Ea.getPos().getY() == 224 && latnok3Ea.getPos().getX() == 160)
                    {                        
                        lat3++;
                    }
                    if (latnok3Ea.getPos().getY() == 224 && latnok3Ea.getPos().getX() == 224)
                    {                        
                        lat3++;
                    }
                    if (latnok3Ea.getPos().getY() == 256 && latnok3Ea.getPos().getX() == 224)
                    {                        
                        lat3++;
                    }                   
                    if (latnok3Ea.getPos().getY() == 256 && latnok3Ea.getPos().getX() == 320)
                    {                        
                        lat3 = 7;
                    }
                    switch (lat3)
                    {
                        case 0:
                            game.right(latnok3Ea);
                            game.update(latnok3Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 1:
                            game.down(latnok3Ea);
                            game.update(latnok3Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 2:
                            game.left(latnok3Ea);
                            game.update(latnok3Ea, latnokMoveL, latnokMoveL.size(), 32, 32, 0, true);
                            break;
                        case 3:
                            game.down(latnok3Ea);
                            game.update(latnok3Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 4:
                            game.right(latnok3Ea);
                            game.update(latnok3Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 5:
                            game.down(latnok3Ea);
                            game.update(latnok3Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);                            
                            break;
                        case 6:
                            game.right(latnok3Ea);
                            game.update(latnok3Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                            break;
                        case 7:
                            latnok3E.setAbsPosi(320, 256);
                            game.update(latnok3E, npcIdleL, npcIdleL.size(), 32, 32, 0, true);
                            break;
                    }
                }

                if (l.getPos().getY() == 256 && l.getPos().getX() == 224 && !d)
                {
                    game.nextTxt(false);
                    game.resetPage();
                    dontA = false;
                    d = true;
                }
                if (l.getPos().getY() == 256 && l.getPos().getX() == 224 && !d)



                break;
            case 1:
                
                game.render(chstE);

                game.update(antEI1, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                game.update(antEI2, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                game.update(antEI3, npcIdleL, npcIdleL.size(), 32, 32, 0, true);
                
                break;
            case 2:
                game.render(wtrE);
                game.render(bogyesz1E);

                game.update(urgeE1, urgeIdleL, urgeIdleL.size(), 32, 32, 0, true);
                game.update(urgeE2, urgeIdleL, urgeIdleL.size(), 32, 32, 0, true);
                game.update(latnokMeregE, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                
                break;
            case 3:
                game.render(chst2E);

                game.render(bogyesz2E);
                game.render(bogyesz3E);
                game.render(bogyesz4E);

                game.update(jujjEzNagyonKigyoE1, nagyonIdleR, nagyonIdleR.size(), 32, 32, 0, true);
                game.update(jujjEzNagyonKigyoE2, nagyonIdleL, nagyonIdleL.size(), 32, 32, 0, true);
                
                break;
        }

        // terbeli kövek render
        game.updateMap(rocksEntity, map);

        switch (game.getMap())  {
            case 0:
                // felhők renderelése és ütközések ellenőrzése és lekezelése
                // planetR1 = renderPlanet(game, planet1, planetR1, l);

                break;
            case 1:
                // felhők renderelése és ütközések ellenőrzése és lekezelése
                planetR2 = renderPlanet(game, planet1, planetR2, l);

                break;
            case 2:
                // felhők renderelése és ütközések ellenőrzése és lekezelése
                planetR3 = renderPlanet(game, planet1, planetR3, l);

                break;
            case 3:
                // felhők renderelése és ütközések ellenőrzése és lekezelése
                planetR4 = renderPlanet(game, planet1, planetR4, l);

                break;
        }
        // szöveg háttér
        game.render(txtbckground);
        game.renderText(fnt);
        // input box
        game.render(inptxtbckground);
        game.renderInputText(command, fnt);
        // rendererbe tötött elemek képernyőre helyezése
        game.display();
    }
    game.mapReset();
    game.nextTxt(next);
}
/**
 * \brief Glacies pálya megjelenítése.
 *
 */
void Plnt::glacies()
{  
    int i = 0;

    // első mapra állítás
    game.mapReset();
    // egész számokból álló párokból álló vektorok definiálása
    std::vector<std::pair<int, int>> map;
    std::vector<std::pair<int, int>> npcIdleR;
    std::vector<std::pair<int, int>> npcIdleL;
    std::vector<std::pair<int, int>> csontiIdleR;
    std::vector<std::pair<int, int>> csontiIdleL;

    // obomar üresjárati
    // jobb
    npcIdleR = { { 0,   0}, {32,   0} };
    // bal
    npcIdleL = { { 64,   0}, {96,  0} };

    // csonti üresjárati
    // jobb
    csontiIdleR = { {  0, 0}, { 64, 0} };
    // bal
    csontiIdleL = { {128, 0}, {192, 0} };

    // map
    map             = { {  0,   0}, {384,   0},
                        {  0, 384}, {384, 384}, {768, 384} };


    // LyRs összes animációját tartalmazó sprite sheet betöltése
    SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/LyRs/lyrs_sprite_sheet.png");
    Entity l(V2F(64, 96), lyrsAnim);
    l.setPosi(64, 96);
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);
    // beviteli mező háttere
    SDL_Texture* inputTextBckGround = game.loadTexture("res/gfx/Objects/blck_bckgrnd.png");
    Entity inptxtbckground(V2F(0, 384), inputTextBckGround);

    // térkép hátterének betöltése
    SDL_Texture* background = game.loadTexture("res/gfx/Glacies_map/Glacies_map.png");
    Entity pl(V2F(0, 0), background);

    // női odomár üresjárat
    SDL_Texture* odoW = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_woman_idle.png");
    Entity odoWE(V2F(64, 288), odoW);
    // férfi odomár üresjárat
    SDL_Texture* odoM = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_man_idle.png");
    Entity odoME(V2F(96, 256), odoM);
    // gyerek odomár üresjárat
    SDL_Texture* odoK = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_kid_idle.png");
    Entity odoKE(V2F(128, 256), odoK);
    
    // őr odomár üresjárat 1
    SDL_Texture* odoO1 = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_man_idle.png");
    Entity odoO1E(V2F(96, 128), odoO1);
    // őr odomár üresjárat 2
    SDL_Texture* odoO2 = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_man_idle.png");
    Entity odoO2E(V2F(96, 192), odoO2);
    // őr odomár üresjárat 3
    SDL_Texture* odoO3 = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_man_idle.png");
    Entity odoO3E(V2F(160, 192), odoO3);
    // őr odomár üresjárat 4
    SDL_Texture* odoO4 = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_man_idle.png");
    Entity odoO4E(V2F(160, 128), odoO4);
    // őr odomár üresjárat 5
    SDL_Texture* odoO5 = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_man_idle.png");
    Entity odoO5E(V2F(224, 128), odoO5);
    // őr odomár üresjárat 6
    SDL_Texture* odoO6 = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_man_idle.png");
    Entity odoO6E(V2F(224, 192), odoO6);

    // odomár KIRÁLY üresjárat
    SDL_Texture* odoKing = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_odomar_king_idle.png");
    Entity odoKingE(V2F(320, 150), odoKing);

    // csonti lópaci üresjárat
    SDL_Texture* csonti = game.loadTexture("res/gfx/Animations/Glacies_bolygo/glacies_bonehorse_idle.png");
    Entity csontiE(V2F(256, 256), csonti);

    // Entity vector létrehozása
    std::vector<Entity> planet1 = {};
    planet1 = LoadPlanet(game, "res/gfx/Glacies_map/galcies_felho.png");
    // logikai változókat tartalmazó vektorok definiálása
    std::vector<bool> planetR1 = {};
    planetR1 = setPlanetPos();

    // felszínen lévő felhők kiszűrése
    for (bool z : planetR1)
    {
        if (planet1[i].getPos().getY() < 250)
        {
            planetR1[i] = false;
        }
        i++;
    }

    std::vector<bool> planetR2 = {};
    planetR2 = setPlanetPos();

    std::vector<bool> planetR3 = {};
    planetR3 = setPlanetPos();

    std::vector<bool> planetR4 = {};
    planetR4 = setPlanetPos();

    // parancs választó deklarálása
    Router r = Router();

    // összes logikai változó a gombnyomásokhoz
    bool gameRunning = true;
    bool attack = false;
    bool fel = false;
    bool le = false;
    bool jobbra = false;
    bool balra = false;
    bool flip = true;
    bool crack = false;
    bool nxttxt = true;
    bool belep = false;
    // esemény létrehozása
    SDL_Event event;
    // FPS limitációhoz szükséges változók
    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();
    // input text 
    std::string command;
    Command c = Command();

    gameRunning = true;
    // glacies
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
                                    if (command == "LAPOZZ")
                                    {
                                        game.nextPage();
                                    }
                                    if (command == "TAMADAS")
                                    {
                                        attack = true;
                                    }
                                    if (command == "POSI")
                                    {
                                        std::cout << " CURRENT POSITION: " << l.getPos().getY() << " \t " << l.getPos().getX() << std::endl;
                                    }
                                    if (command == "TARGET")
                                    {
                                        std::cout << " TARGET COORDINATE: " << l.getTargetY() << " \t " << l.getTargetX() << std::endl;
                                    }
                                    if (command == "BELEP")
                                    {
                                        belep = true;
                                    }
                                    c.make(command);
                                    r.route(c.getCommand(), c.getItem(), l);
                                    c.reset();

                                    command = "";
                                }
                        }
                }
            }
            accum -= timeStep;
        }           
        const float alpha = accum / timeStep;
        // megfelelő map kirenderelése
        if (game.getMap() == 0 && l.getPos().getY() == 32 && l.getPos().getX() >= 384)
        {
            // MAP 1 -> MAP 2
            game.setMap(1);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }
        else if (game.getMap() == 1 && l.getPos().getY() == 32 && l.getPos().getX() <= -32)
        {
            // MAP 2 -> MAP 1
            game.setMap(0);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY() >= 384 && l.getPos().getX() == 32)
        {
            // MAP 1 -> MAP 3
            game.setMap(2);

            l.setPosi(0, -416);

            l.setTarget(3, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() <= -32 && l.getPos().getX() == 32)
        {
            // MAP 3 -> MAP 1
            game.setMap(0);

            l.setPosi(0, 416);

            l.setTarget(1, 1);
        }
        else if (game.getMap() == 1 && l.getPos().getY() == 256 && l.getPos().getX() <= -32)
        {
            // MAP 2 -> MAP 1
            game.setMap(0);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY() == 256 && l.getPos().getX() >= 384)
        {
            // MAP 1 -> MAP 2
            game.setMap(1);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }        
        else if (game.getMap() == 1 && l.getPos().getY()  >= 384 && l.getPos().getX() == 256)
        {
            // MAP 2 -> MAP 4
            game.setMap(3);

            l.setPosi(0, -416);

            l.setTarget(3, 1);
        }
        else if (game.getMap() == 3 && l.getPos().getY() == -32 && l.getPos().getX() == 256)
        {
            // MAP 4 -> MAP 2
            game.setMap(1);

            l.setPosi(0, 416);

            l.setTarget(1, 1);
        }
        else if (game.getMap() == 3 && l.getPos().getY() == 256 && l.getPos().getX() == 288 && belep)
        {
            // MAP 4 -> MAP 5
            game.setMap(4);

            l.setPosi(-288, -96);

            belep = false;
        }
        else if (game.getMap() == 4 && l.getPos().getY() == 160 && l.getPos().getX() == 0 && belep)
        {
            // MAP 5 -> MAP 4
            game.setMap(3);

            l.setPosi(288, 96);

            belep = false;
        }

        // irányok beállítása
        switch (l.getDirection())
        {
        case 0:
            break;
        case 1:
            // fel
            fel = true;
            break;
        case 2:
            // jobbra
            jobbra = true;
            break;     
        case 3:
            // le
            le = true;
            break;
        case 4: 
            // balra
            balra = true;
            break;
        case 5:
            attack = true;
        default:
            break;
        }
        
        // először a háttér kirajzolása
        game.updateMap(pl, map);

        if (!fel && !le && !balra && !jobbra && !attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleR, lyrsIdleR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleL, lyrsIdleL.size(), 32, 32, 0, true);
            }
            // if (l.getPos().getX() != l.getTargetX() || l.getPos().getY() != l.getTargetY())
            // {
            //     l.setPosi(l.getPos().getX(), l.getPos().getY());
            // } 
        }
        // felfele gomb megnyomva?
        if (fel && !attack)
        {                
            if (l.getPos().getY() <= l.getTargetY())
            {
                fel = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása fel
                game.up(l);
            }

            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // lefele gomb megnyomva?
        if (le && !attack)
        {
            if (l.getPos().getY() >= l.getTargetY())
            {
                le = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása le
                game.down(l);
            }
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // balra gomb megnyomva?
        if (balra && !attack)
        {
            if (l.getPos().getX() <= l.getTargetX())
            {
                balra = false;
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása balra
                game.left(l);
            }
            // LyRs balra mozog animáció következő kockája
            game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            // összes animáció balra néz
            flip = false;
        }
        // jobbra gomb megnyomva?
        if (jobbra && !attack)
        {
            if (l.getPos().getX() >= l.getTargetX())
            {
                jobbra = false;
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása jobbra
                game.right(l);
            }
            // LyRs jobbra mozog animáció következő kockája
            game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            // összes animáció jobbra néz
            flip = true;
        }
        // szóköz gomb megnyomva?
        if (attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra támad animáció következő kockája
                attack = game.update(l, lyrsLaserR, lyrsLaserR.size(), 64, 32, 0, false);
            }
            else
            {
                // LyRs balra támad animáció következő kockája
                attack = game.update(l, lyrsLaserL, lyrsLaserL.size(), 64, 32, 32, false);
            }
            if ((l.getPos().getY() == 352 && l.getPos().getX() == 288) || (l.getPos().getY() == 352 && l.getPos().getX() == 320))
            {
                crack = true;
            }
        }

        switch (game.getMap())  {
            case 0:
                break;
            case 1:
                game.update(odoWE, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                game.update(odoME, npcIdleL, npcIdleR.size(), 32, 32, 0, true);
                game.update(odoKE, npcIdleL, npcIdleR.size(), 32, 32, 0, true);

                break;
            case 2:
                game.update(csontiE, csontiIdleL, csontiIdleL.size(), 64, 32, 0, true);

                break;
            case 3:
                break;
            case 4:
                game.update(odoO1E, npcIdleL, npcIdleR.size(), 32, 32, 0, true);
                game.update(odoO2E, npcIdleL, npcIdleR.size(), 32, 32, 0, true);
                game.update(odoO3E, npcIdleL, npcIdleR.size(), 32, 32, 0, true);
                game.update(odoO4E, npcIdleL, npcIdleR.size(), 32, 32, 0, true);
                game.update(odoO5E, npcIdleL, npcIdleR.size(), 32, 32, 0, true);
                game.update(odoO6E, npcIdleL, npcIdleR.size(), 32, 32, 0, true);
                game.update(odoKingE, npcIdleL, npcIdleR.size(), 32, 32, 0, true);


                break;
        }

        switch (game.getMap())  {
            case 0:
                // felhők renderelése és ütközések ellenőrzése és lekezelése
                planetR1 = renderPlanet(game, planet1, planetR1, l);

                break;
            case 2:
                // felhők renderelése és ütközések ellenőrzése és lekezelése
                planetR3 = renderPlanet(game, planet1, planetR3, l);

                break;
        }

        // szöveg háttér
        game.render(txtbckground);
        game.renderText(fnt);
        // input mező
        game.render(inptxtbckground);
        game.renderInputText(command, fnt);
        // rendererbe tötött elemek képernyőre helyezése
        game.display();
        // TODO:
        // delete c; 
    }
    game.mapReset();
    game.clear();
}
/**
 * \brief Planthea pálya megjelenítése.
 *
 */
void Plnt::planthea()
{  
    int i = 0;

    // első mapra állítás
    game.setMap(2);
    // egész számokból álló párokból álló vektorok definiálása
    std::vector<std::pair<int, int>> map;
    std::vector<std::pair<int, int>> npcIdleR;
    std::vector<std::pair<int, int>> npcIdleL;
    std::vector<std::pair<int, int>> csontiIdleR;
    std::vector<std::pair<int, int>> csontiIdleL;
    std::vector<std::pair<int, int>> prpA;

    // obomar üresjárati
    // jobb
    npcIdleR = { { 0,   0}, {32,   0} };
    // bal
    npcIdleL = { { 64,   0}, {96,  0} };

    // csonti üresjárati
    // jobb
    csontiIdleR = { {  0, 0}, { 64, 0} };
    // bal
    csontiIdleL = { {128, 0}, {192, 0} };

    // map
    map             = { {  0,   0}, {384,   0},
                        {  0, 384}, {384, 384}, {768, 384} };
    // propeller 
    prpA =  { {  0, 0}, {79, 0} };

    // LyRs összes animációját tartalmazó sprite sheet betöltése
    SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/LyRs/lyrs_sprite_sheet.png");
    Entity l(V2F(96, 96), lyrsAnim);
    l.setPosi(96, 96);
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);
    // beviteli mező háttere
    SDL_Texture* inputTextBckGround = game.loadTexture("res/gfx/Objects/blck_bckgrnd.png");
    Entity inptxtbckground(V2F(0, 384), inputTextBckGround);

    // térkép hátterének betöltése
    SDL_Texture* background = game.loadTexture("res/gfx/Planthea_map/planthea_map.png");
    Entity pl(V2F(0, 0), background);

    SDL_Texture* scroll1 = game.loadTexture("res/gfx/Objects/scroll4.png");
    SDL_Texture* scroll2 = game.loadTexture("res/gfx/Objects/scroll3.png");
    SDL_Texture* scroll3 = game.loadTexture("res/gfx/Objects/scroll2.png");
    SDL_Texture* scroll4 = game.loadTexture("res/gfx/Objects/scroll1.png");
    Entity scroll1E(V2F(108, 150), scroll1);
    Entity scroll2E(V2F(164, 140), scroll2);
    Entity scroll3E(V2F(204, 128), scroll3);
    Entity scroll4E(V2F(262, 128), scroll4);
    scroll1E.setSize(16, 16);
    scroll2E.setSize(16, 16);
    scroll3E.setSize(16, 16);
    scroll4E.setSize(16, 16);

    // rönkök
    SDL_Texture* wood1 = game.loadTexture("res/gfx/Objects/planthea_wood.png");
    SDL_Texture* wood2 = game.loadTexture("res/gfx/Objects/planthea_wood.png");
    SDL_Texture* wood3 = game.loadTexture("res/gfx/Objects/planthea_wood.png");
    SDL_Texture* wood4 = game.loadTexture("res/gfx/Objects/planthea_wood.png");
    SDL_Texture* wood5 = game.loadTexture("res/gfx/Objects/planthea_wood.png");

    Entity wood1E(V2F(  8,  48), wood1);
    Entity wood2E(V2F(176,  40), wood2);
    Entity wood3E(V2F(  8, 208), wood3);
    Entity wood4E(V2F(264, 240), wood4);
    Entity wood5E(V2F(230,  16), wood5);

    wood1E.setSize(16, 16);
    wood2E.setSize(16, 16);
    wood3E.setSize(16, 16);
    wood4E.setSize(16, 16);
    wood5E.setSize(16, 16);

    // másik bogyeszok
    SDL_Texture* berry1 = game.loadTexture("res/gfx/Objects/planthea_berry.png");
    SDL_Texture* berry2 = game.loadTexture("res/gfx/Objects/planthea_berry.png");
    SDL_Texture* berry3 = game.loadTexture("res/gfx/Objects/planthea_berry.png");
    SDL_Texture* berry4 = game.loadTexture("res/gfx/Objects/planthea_berry.png");
    SDL_Texture* berry5 = game.loadTexture("res/gfx/Objects/planthea_berry.png");

    Entity berry1E(V2F(  8, 136), berry1);
    Entity berry2E(V2F(168,  16), berry2);
    Entity berry3E(V2F( 72, 368), berry3);
    Entity berry4E(V2F(104, 144), berry4);
    Entity berry5E(V2F(104, 304), berry5);

    berry1E.setSize(16, 16);
    berry2E.setSize(16, 16);
    berry3E.setSize(16, 16);
    berry4E.setSize(16, 16);
    berry5E.setSize(16, 16);

    // helikopter helikopter
    SDL_Texture* prp = game.loadTexture("res/gfx/Planthea_map/mill_propeller.png");
    Entity prpE(V2F(39, 206), prp);

    // parancs választó deklarálása
    Router r = Router();

    // összes logikai változó a gombnyomásokhoz
    bool gameRunning = true;
    bool attack = false;
    bool fel = false;
    bool le = false;
    bool jobbra = false;
    bool balra = false;
    bool flip = true;
    bool crack = false;
    bool nxttxt = true;
    bool belep = false;
    // esemény létrehozása
    SDL_Event event;
    // FPS limitációhoz szükséges változók
    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();
    // input text 
    std::string command;
    Command c = Command();

    gameRunning = true;
    // glacies
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
                                    if (command == "LAPOZZ")
                                    {
                                        game.nextPage();
                                    }
                                    if (command == "TAMADAS")
                                    {
                                        attack = true;
                                    }
                                    if (command == "POSI")
                                    {
                                        std::cout << " CURRENT POSITION: " << l.getPos().getY() << " \t " << l.getPos().getX() << std::endl;
                                    }
                                    if (command == "TARGET")
                                    {
                                        std::cout << " TARGET COORDINATE: " << l.getTargetY() << " \t " << l.getTargetX() << std::endl;
                                    }
                                    if (command == "BELEP")
                                    {
                                        belep = true;
                                    }
                                    c.make(command);
                                    r.route(c.getCommand(), c.getItem(), l);
                                    c.reset();

                                    command = "";
                                }
                        }
                }
            }
            accum -= timeStep;
        }           
        const float alpha = accum / timeStep;
        // megfelelő map kirenderelése
        if (game.getMap() == 2 && l.getPos().getY() == -32 && l.getPos().getX() <= 224)
        {
            // MAP 3 -> MAP 1
            game.setMap(0);

            l.setPosi(0, 416);

            l.setTarget(1, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY() >= 384 && l.getPos().getX() == 224)
        {
            // MAP 1 -> MAP 3
            game.setMap(2);

            l.setPosi(0, -416);

            l.setTarget(3, 1);
        }
               
               
        else if (game.getMap() == 3 && l.getPos().getY() == -32 && l.getPos().getX() <= 64)
        {
            // MAP 4 -> MAP 2
            game.setMap(1);

            l.setPosi(0, 416);

            l.setTarget(1, 1);
        }
        else if (game.getMap() == 1 && l.getPos().getY() >= 384 && l.getPos().getX() == 64)
        {
            // MAP 2 -> MAP 4
            game.setMap(3);

            l.setPosi(0, -416);

            l.setTarget(3, 1);
        }

        else if (game.getMap() == 2 && l.getPos().getY() <= 96 && l.getPos().getX() == 384)
        {
            // MAP 3 -> MAP 4
            game.setMap(3);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }
        else if (game.getMap() == 3 && l.getPos().getY() == 96 && l.getPos().getX() <= -32)
        {
            // MAP 4 -> MAP 3
            game.setMap(2);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() <= 256 && l.getPos().getX() == 384)
        {
            // MAP 3 -> MAP 4
            game.setMap(3);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }
        else if (game.getMap() == 3 && l.getPos().getY() == 256 && l.getPos().getX() <= -32)
        {
            // MAP 4 -> MAP 3
            game.setMap(2);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() <= 320 && l.getPos().getX() == 384)
        {
            // MAP 3 -> MAP 4
            game.setMap(3);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }
        else if (game.getMap() == 3 && l.getPos().getY() == 320 && l.getPos().getX() <= -32)
        {
            // MAP 4 -> MAP 3
            game.setMap(2);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY() == 64 && l.getPos().getX() >= 384)
        {
            // MAP 1 -> MAP 2
            game.setMap(1);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }        
        else if (game.getMap() == 1 && l.getPos().getY()  >= 64 && l.getPos().getX() == -32)
        {
            // MAP 2 -> MAP 1
            game.setMap(0);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY() == 128 && l.getPos().getX() >= 384)
        {
            // MAP 1 -> MAP 2
            game.setMap(1);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }        
        else if (game.getMap() == 1 && l.getPos().getY()  >= 128 && l.getPos().getX() == -32)
        {
            // MAP 2 -> MAP 1
            game.setMap(0);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 3 && l.getPos().getY() == 288 && l.getPos().getX() == 288 && belep)
        {
            // MAP 4 -> MAP 5
            game.setMap(4);
        
            l.setPosi(-192, -96);
        
            belep = false;
        }
        else if (game.getMap() == 4 && l.getPos().getY() == 192 && l.getPos().getX() == 96 && belep)
        {
            // MAP 5 -> MAP 4
            game.setMap(3);
        
            l.setPosi(192, 96);
        
            belep = false;
        }

        // irányok beállítása
        switch (l.getDirection())
        {
        case 0:
            break;
        case 1:
            // fel
            fel = true;
            break;
        case 2:
            // jobbra
            jobbra = true;
            break;     
        case 3:
            // le
            le = true;
            break;
        case 4: 
            // balra
            balra = true;
            break;
        case 5:
            attack = true;
        default:
            break;
        }
        
        // először a háttér kirajzolása
        game.updateMap(pl, map);

        if (!fel && !le && !balra && !jobbra && !attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleR, lyrsIdleR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleL, lyrsIdleL.size(), 32, 32, 0, true);
            }
            // if (l.getPos().getX() != l.getTargetX() || l.getPos().getY() != l.getTargetY())
            // {
            //     l.setPosi(l.getPos().getX(), l.getPos().getY());
            // } 
        }
        // felfele gomb megnyomva?
        if (fel && !attack)
        {                
            if (l.getPos().getY() <= l.getTargetY())
            {
                fel = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása fel
                game.up(l);
            }

            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // lefele gomb megnyomva?
        if (le && !attack)
        {
            if (l.getPos().getY() >= l.getTargetY())
            {
                le = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása le
                game.down(l);
            }
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // balra gomb megnyomva?
        if (balra && !attack)
        {
            if (l.getPos().getX() <= l.getTargetX())
            {
                balra = false;
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása balra
                game.left(l);
            }
            // LyRs balra mozog animáció következő kockája
            game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            // összes animáció balra néz
            flip = false;
        }
        // jobbra gomb megnyomva?
        if (jobbra && !attack)
        {
            if (l.getPos().getX() >= l.getTargetX())
            {
                jobbra = false;
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása jobbra
                game.right(l);
            }
            // LyRs jobbra mozog animáció következő kockája
            game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            // összes animáció jobbra néz
            flip = true;
        }
        // szóköz gomb megnyomva?
        if (attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra támad animáció következő kockája
                attack = game.update(l, lyrsLaserR, lyrsLaserR.size(), 64, 32, 0, false);
            }
            else
            {
                // LyRs balra támad animáció következő kockája
                attack = game.update(l, lyrsLaserL, lyrsLaserL.size(), 64, 32, 32, false);
            }
            if ((l.getPos().getY() == 352 && l.getPos().getX() == 288) || (l.getPos().getY() == 352 && l.getPos().getX() == 320))
            {
                crack = true;
            }
        }

        switch (game.getMap())  {
            case 0:
                game.render(wood1E);
                game.render(wood2E);
                game.render(wood3E);
                game.render(wood4E);
                game.render(berry4E);
                game.render(berry5E);


                break;
            case 1:
                game.render(wood5E);
                game.render(berry1E);
                game.render(berry2E);
                game.render(berry3E);

                break;
            case 2:
                game.update(prpE, prpA, prpA.size(), 79, 79, 0, true);

                break;
            case 3:
                break;
            case 4:
                game.render(scroll1E);
                game.render(scroll2E);
                game.render(scroll3E);
                game.render(scroll4E);

                break;
        }
        // szöveg háttér
        game.render(txtbckground);
        game.renderText(fnt);
        // input mező
        game.render(inptxtbckground);
        game.renderInputText(command, fnt);
        // rendererbe tötött elemek képernyőre helyezése
        game.display();
        // TODO:
        // delete c; 
    }
    game.mapReset();
    game.clear();
}
