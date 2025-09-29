#include <SFML/Graphics.hpp>
#include<random>
#include <ctime>
//#include <SFML/Audio.hpp>
#include<iostream>
#include <map>
using namespace sf;
using namespace std;
//int main()
//{
//    char state[3][3] = {
//        {' ',' ',' '},
//        {' ',' ',' '},
//        {' ',' ',' '}
//
//    };
//    int cu_x = 1;
//    int cu_y = 1;
//    bool is_x_turn = true;
//    char winer = ' ';
//    
//    RenderWindow window(sf::VideoMode({ 600, 600 }), "title");
//    RenderWindow window2(sf::VideoMode({ 200, 200 }), "title");
//     
//    CircleShape c;
//    c.setPointCount(60);
//    RectangleShape l;
//    RectangleShape curser;
//    RectangleShape curser1;
//    float w = window.getView().getSize().x;
//    float h = window.getView().getSize().y;
//    float min = (w < h) ? w : h;
//
//    auto drawx = [&](float w, float h) {
//        l.setSize({ 200.f,20.f });
//        l.setOrigin(l.getGeometricCenter());
//        l.setFillColor(sf::Color(0, 170, 255));
//        l.setPosition({ w,h });
//        l.setRotation(degrees(45));
//        window.draw(l);
//        l.setRotation(degrees(-45)); 
//        window.draw(l);
//        };   
//    auto drawo = [&](float w, float h) {
//        c.setRadius(90.f);
//        c.setOrigin(c.getGeometricCenter());
//        c.setFillColor(sf::Color::Transparent);
//        c.setOutlineColor(Color(255, 170, 255));
//        c.setOutlineThickness(-20.f);
//        c.setPosition({ w,h });
//        window.draw(c);
//        };
//    auto drawwinl = [&](float w, float h,float angle) {
//        l.setSize({ 600.f,10.f });
//        l.setOrigin(l.getGeometricCenter());
//        l.setFillColor(sf::Color::Black);
//        l.setPosition({ w,h });
//        l.setRotation(degrees(angle));
//        window.draw(l);
//        };
//    auto drawcur1 = [&](float w, float h) {
//        curser1.setSize({ 200.f, 200.f });
//        curser1.setOrigin(curser.getGeometricCenter());
//        curser1.setFillColor(sf::Color::Transparent);
//        curser.setOutlineColor(sf::Color::Black);
//        curser1.setOutlineThickness(-10.f);
//        curser1.setPosition({ w, h });
//        window.draw(curser1);
//        };
//    auto drawcur = [&](float w, float h) {
//        curser.setSize({ 200.f, 200.f });
//        curser.setOrigin(curser.getGeometricCenter());
//        curser.setFillColor(sf::Color::Transparent);
//        curser.setOutlineThickness(-10.f);
//        curser.setPosition({ w, h });
//        window.draw(curser);
//        };
//    
//
//     
//    while (window.isOpen() ){
//        
//        while (std::optional event = window.pollEvent()) 
//        {
//            float w = window.getView().getSize().x;
//            float h = window.getView().getSize().y;
//            float min = (w < h) ? w : h;
//            
//             
//            if (event->is<sf::Event::Closed>())
//            {
//                window.close();                                            
//            } 
//            else if (event->is<sf::Event::Resized>())
//            {
//           
//            }
//            else if (auto* key = event->getIf<sf::Event::KeyPressed>())
//            {
//                //move the curser
//                if (winer == ' ')
//                {
//                    if ((key->scancode == Keyboard::Scancode::Left) and (cu_y > 0)) {
//                        cu_y--;
//                    }
//                    else if ((key->scancode == Keyboard::Scancode::Right) and (cu_y < 2)) {
//                        cu_y++;
//                    }
//                    else if ((key->scancode == Keyboard::Scancode::Up) and (cu_x > 0)) {
//                        cu_x--;
//                    }
//                    else if ((key->scancode == Keyboard::Scancode::Down) and (cu_x < 2)) {
//                        cu_x++;
//                    }
//
//                    //get user inputs
//                    if ((key->scancode == Keyboard::Scancode::Space) and (state[cu_x][cu_y] == ' ')) {//(state[cu_y][cu_x] = ' ') for mark on another 
//                        if (is_x_turn) {
//                            state[cu_x][cu_y] = 'X';
//                        }
//                        else {
//                            state[cu_x][cu_y] = 'O';
//                        }
//                        is_x_turn = not is_x_turn;
//
//
//                    }
//                }
//                //restart the game
//                if (key->scancode == Keyboard::Scancode::Escape) {
//                    for (int i = 0; i < 3; i++)
//                    {
//                        for (int j = 0; j < 3; j++) {
//                            state[i][j] = ' ';
//                        }
//                    }
//                    cu_x = 1;
//                    cu_y = 1;
//                    is_x_turn = true;
//                    winer = ' ';
//
//                }
//            }
//        }
//
//       
//
//        window.clear(sf::Color::Yellow);
//
//        
//
//        //drawx(w/2,h/2);
//
//        for (int j = 0; j < 3; j++)
//        {
//            for (int i = 0; i < 3; i++)
//            {
//                if (state[j][i]=='O')
//                {
//                    drawo(w / 2 + 200.f * (i - 1), h / 2 + 200.f * (j - 1));
//                }else if (state[j][i] == 'X')
//                {
//                    drawx(w / 2 + 200.f * (i - 1), h / 2 + 200.f * (j - 1));
//                }
//               
//            }
//        }
//        for (int i = 0; i <3 ; i++)
//        {
//            if ((state[i][0] != ' ') and (state[i][0] == state[i][1]) and (state[i][1] == state[i][2])) {
//                drawwinl(w / 2, h / 2 + 200.f * (i - 1), 0.f);
//                winer = state[i][0];
//            }
//                
//            if ((state[0][i] != ' ') and (state[0][i] == state[1][i]) and (state[1][i] == state[2][i])) {
//                drawwinl(w / 2 + 200.f * (i - 1), h / 2, 90.f);
//                winer = state[0][i];
//            }
//               
//        }
//        if ((state[0][0] != ' ') and (state[0][0] == state[1][1]) and (state[1][1] == state[2][2])) {
//            drawwinl(w / 2 , h / 2, 45.f);
//            winer = state[0][0];
//        }
//        if ((state[0][2] != ' ') and (state[0][2] == state[1][1]) and (state[1][1] == state[2][0])) {
//            drawwinl(w / 2, h / 2, -45.f);
//            winer = state[0][2];
//        }
//        for (int j = 0; j < 3; j++)
//        {
//            for (int i = 0; i < 3; i++)
//            {
//                drawcur1(w / 2 + 200.f * (i - 1), h / 2+200.f*(j-1));
//            }
//        }
//        drawcur(w / 2 + 200.f * (cu_y - 1), h / 2 + 200.f * (cu_x - 1));
//        
//        window.display();
//        window2.clear(sf::Color::Black);
//        window2.display();
//
//    }
//     
//}
//int main() {
//	//create window
//	RenderWindow window(sf::VideoMode({ 500,500 }),"snake");
//	RectangleShape r;
//	
//
//	auto draw_r = [&](float w,float h) {
//		r.setSize({ 50.f,50.f });
//		r.setFillColor(sf::Color::Transparent);
//		r.setOutlineThickness(-10.f);
//		r.setOutlineColor(sf::Color::Black);
//		r.setOrigin({25.f,25.f});
//		r.setPosition({ w,h });
//		window.draw(r);
//		};
//	//control the window process
//	while (window.isOpen()) 
//	{
//		float w = window.getView().getSize().x;
//		float h = window.getView().getSize().y;
//		//control the window events
//		while (optional event = window.pollEvent())
//		{
//			if (event->is<sf::Event::Closed>())
//			{
//				window.close();
//			}
//			else if (event->is<sf::Event::Resized>())
//			{
//
//			}
//		}
//		window.clear(sf::Color::Magenta);
//		for (int i = 0; i < 10; i++)
//		{
//			for (int j = 0; j < 10; j++)
//			{
//				draw_r(w/20 + 50.f * (j), h/20 + 50.f*(i));
//			}
//		}
//		//draw_r(w / 20 , h / 20 );
//		
//		window.display();
//	}
//}
class button {
public:
	RectangleShape r;
	void draww_roll(sf::RenderWindow& window) {
		r.setSize({ 100.f,50.f });
		r.setOrigin(r.getGeometricCenter());
		r.setFillColor(sf::Color::Blue);
		r.setPosition({ 150.f, 200.f });
		window.draw(r);
		 
	}
	void draww_reset(sf::RenderWindow& window) {
		r.setSize({ 105.f,50.f });
		r.setOrigin(r.getGeometricCenter());
		r.setFillColor(sf::Color::Blue);
		r.setPosition({ 150.f, 290.f });
		window.draw(r);
	}
	void draww_dice(sf::RenderWindow& window) {
		r.setSize({ 100.f,100.f });
		r.setOrigin(r.getGeometricCenter());
		r.setFillColor(sf::Color::White);
		r.setPosition({ 300.f, 200.f });
		window.draw(r);
	}
};
class mouse {
public:
	bool ispressed = true;
	bool onpress = false;
	bool onrelease = false;
	 
	void update() {
		onpress = false;
		onrelease = false;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
		{
			if (ispressed)
				onpress = true;
			ispressed = false;
		}
		else 
		{
			ispressed = true;
		}
	}
};
class random {
public:
	int tot = 0;
	int genarate() {
		mt19937 n1(time(0)); 
		uniform_int_distribution<> distrib(1, 6);  
		return distrib(n1);  	 
	}
	 
};
class dicePic {
public: 
	
	void player1(sf::RenderWindow& window) {
		sf::Texture p1("1.jpg");
		sf::Sprite s1(p1);
		sf::FloatRect bound = s1.getLocalBounds();
		float w1 = s1.getPosition().x;
		float h1 = s1.getPosition().y;
		float w2 = bound.size.x;//554.554
		float h2 = bound.size.y;
		s1.setOrigin({ w1 + w2 / 2.f,h1 + h2 / 2.f });
		s1.setPosition({ 300.f, 200.f });
		window.draw(s1);
	}
};
class Items {
private:
	sf::Texture p1Texture;
	std::unique_ptr<sf::Sprite> p1Sprite;    

public:
	Items() : p1Sprite(nullptr) {}  

	bool init(const std::string& texturePath) {
		if (!p1Texture.loadFromFile(texturePath))
			return false;
		p1Sprite = std::make_unique<sf::Sprite>(p1Texture);
		auto bound = p1Sprite->getLocalBounds();
		p1Sprite->setOrigin({ bound.size.x / 2.f, bound.size.y / 2.f });
		p1Sprite->setPosition({512.f, 637.f });
		return true;
	}

	void drawPlayer(sf::RenderWindow& window) {
		if (p1Sprite)
			window.draw(*p1Sprite);
	}
	void setPosition(sf::Vector2f pos) {
		if (p1Sprite)
			p1Sprite->setPosition(pos);
	}
};


int main() {
	
	std::vector<sf::Vector2f> boardSquares(100);

	float startX = 512.f;  
	float startY = 625.f;  
	float step = 55.f;     

	bool leftToRight = true;  

	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {
			int index = row * 10 + (leftToRight ? col : (9 - col));
			float x = startX + col * step;
			float y = startY - row * step;
			boardSquares[index] = sf::Vector2f(x, y);
		}
		leftToRight = !leftToRight;  
	}





	dicePic dp;
	random r;
	int playerPosition = 0;
	
	//create window
	sf::VideoMode dekstop = sf::VideoMode::getDesktopMode();
	RenderWindow window(dekstop, "snake");
	
	sf::Font font("C:/Windows/Fonts/arial.ttf");
	sf::Text t1(font, "ROLL", 30.f);
	t1.setFillColor(sf::Color::Green);
	sf::FloatRect r1 = t1.getGlobalBounds();
	float wt1 = t1.getPosition().x;
	float ht1 = t1.getPosition().y;
	float wt2 = r1.size.x; 
	float ht2 = r1.size.y;
	t1.setOrigin({wt1+wt2/2.f,ht1+ht2/2.f});
	t1.setPosition({ 150.f, 190.f });

	sf::Text t2(font, "RESET", 30.f);
	t2.setFillColor(sf::Color::Green);
	sf::FloatRect r2 = t2.getGlobalBounds();
	float wt11 = t2.getPosition().x;
	float ht11 = t2.getPosition().y;
	float wt22 = r2.size.x;
	float ht22 = r1.size.y;
	t2.setOrigin({ wt11 + wt22/ 2.f,ht11 + ht22 / 2.f });
	t2.setPosition({ 150.f, 280.f });
	 
	button bb;
	mouse m1;
	Items i1;
	i1.init("p1.jpg");
	
	sf::Texture texture("i1.jpeg");
	sf::Sprite sprite(texture); 
	sf::FloatRect bound = sprite.getLocalBounds();
	float w1 = sprite.getPosition().x;
	float h1 = sprite.getPosition().y;
	float w2 = bound.size.x;//554.554
	float h2 = bound.size.y;
	sprite.setOrigin({ w1 + w2 / 2.f,h1 + h2 / 2.f });
	sprite.setPosition({ 750.f, 380.f });
	sprite.setScale({ 550.f / 554.f,550.f / 554.f });
	float wid = w2 - w1;
	float hig = h2 - h1;
	//control the window process
	while (window.isOpen())
	{
		int n = 0, vn = 0,ne=0;
		int l = 0;
		
		//control the window events
		while (optional event = window.pollEvent())
		{
			//set the mouse click state
			m1.update();
			//ROLL state
			

			if ((m1.onpress)and(sf::Mouse::getPosition(window).x>100.f) and (sf::Mouse::getPosition(window).x < 200.f) and (sf::Mouse::getPosition(window).y > 175.f) and (sf::Mouse::getPosition(window).y < 225.f)) {
				 
				cout << "ROLL "<<" ";
				cout<<r.genarate()<<" position ";
				n = r.genarate();
				if (n==1)
				{
					dp.player1(window); 
				}
				std::map<int, int> ladders = { {9, 27},{18,37},{25,54},{28,51},{56,64},{68,88},{79,100} };
				std::map<int, int> snakes = { {16,7},{59,17},{63,19},{67,30},{87,24},{93,69},{95,75},{99,75},{99,77} };
		
				playerPosition += n;
				

				if (ladders.count(playerPosition) > 0) {
					playerPosition = ladders[playerPosition];
					playerPosition += ladders[playerPosition];
					//cout << playerPosition << '\n';
				}
				if (snakes.count(playerPosition) > 0){
					playerPosition = snakes[playerPosition];
					playerPosition -= ladders[playerPosition];
					//cout << playerPosition << '\n';
				}
				if (playerPosition > 100) {
					playerPosition = 100;
				}
					i1.setPosition(boardSquares[playerPosition - 1]);
					cout << playerPosition << '\n';
				
			}
			//RESET state
			if ((m1.onpress) and (sf::Mouse::getPosition(window).x > 150.f-105.f/2) and (sf::Mouse::getPosition(window).x < 150.f + 105.f / 2) and (sf::Mouse::getPosition(window).y > 290.f-55.f/2) and (sf::Mouse::getPosition(window).y < 290.f+55.f/2)||(playerPosition>100)) {
				cout << "RESET\n";
				i1.setPosition(boardSquares[0]); 
				playerPosition = 0;
			}
			 
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (event->is<sf::Event::Resized>())
			{
				sf::View view(sf::FloatRect({ 0.1f,0.1f }, sf::Vector2f(window.getSize())));
				window.setView(view);
			}
			 
 		}
		

		window.clear(sf::Color::Black);
		bb.draww_roll(window);
		bb.draww_reset(window);
		bb.draww_dice(window);
		window.draw(t1);
		window.draw(t2);
		window.draw(sprite);
		i1.drawPlayer(window);
		
		window.display();
	}
}

 