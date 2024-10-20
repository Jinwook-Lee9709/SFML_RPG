#include "Game.h"
//static functions

//Initializer functions

void Game::initWindow()
{
    /*Creates a SFML window using options from a wiidow.ini file.*/
    std::ifstream ifs("Config/window.ini");
    std::string title = "None";
    sf::VideoMode windowBounds(800, 600);
    unsigned framerateLimit = 120;
    bool verticalSyncEnabled = false;
    if (ifs.is_open()) 
    {
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> framerateLimit;
        ifs >> verticalSyncEnabled;
    }
    ifs.close();
    window = new sf::RenderWindow(windowBounds, title);
    window->setFramerateLimit(framerateLimit);
    window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::initStates()
{
    states.push(new MainMenuState(window));

}

//Constructors/Destructors
Game::Game()
{
    initWindow();
    initStates();
}

Game::~Game()
{
	delete window;
    while (!this->states.empty())
    {
        delete states.top();
        this->states.pop();
    }
        
}

void Game::endApplication()
{
    std::cout << "Ending Application!" << std::endl;
}

//Functions
void Game::updateDt()
{
    /*Updated deltaTime*/
    dt = dtClock.restart().asSeconds();
    
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(ev))
    {
        InputManager::UpdateEvent(ev);
    }
}

void Game::update()
{
    InputManager::Clear();
    updateSFMLEvents();
    if (!states.empty())
    {
        states.top()->update(dt);
        if (states.top()->getQuit()) 
        {
            states.top()->endState();
            delete states.top();
            states.pop();
        }
    }
    //Application End
    else
    {
        endApplication();
        window->close();
    } 
   

}

void Game::render()
{
    window->clear();

    //Render items
    if (!states.empty())
        states.top()->render();

    window->display();
}

void Game::run()
{
    while (window->isOpen())
    {
        updateDt();
        update();
        render();
    }
}
