#include "Logic.h"
#include <sstream>
RenderWindow window(VideoMode(1000, 1000), "SFMLDigger");

void Logic()
{
	Texture BGt;
	Sprite BGs;
	Texture BGofft;
	Sprite BGoffs;
	Font font;
	Text Text1, Text2;

	int map[20][20];

	font.loadFromFile("GM.ttf");

	Text1.setFont(font);
	Text1.setStyle(Text::Bold);

	Text2.setFont(font);
	Text2.setStyle(Text::Bold);

	BGt.loadFromFile("Images/BG.png");
	BGs.setTexture(BGt);
	BGs.setPosition(0, 0);

	BGofft.loadFromFile("Images/BGoff.png");
	BGoffs.setTexture(BGofft);
	BGoffs.setPosition(0, 0);

	Player GG;
	Nobbin Tima1, Tima2, Tima3, Tima4, Tima5;
	Death Death;
	Clock Start, Move;
	bool Deathisherebaby;
Restart:
	Deathisherebaby = false;
	Death.setx(0);
	Death.sety(0);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		while (true)
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Num1))
			{
				int lvl1[20][20] =
				{
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
					3,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,2,2,3,
					3,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,2,3,
					3,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,2,3,
					3,0,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,2,2,3,
					3,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,3,
					3,1,2,2,1,1,1,1,0,0,0,0,0,0,2,1,1,1,2,3,
					3,1,1,1,2,2,2,2,1,0,0,1,2,2,2,0,0,2,2,3,
					3,1,1,1,1,1,1,2,2,2,2,2,2,2,0,0,0,2,2,3,
					3,0,1,1,1,1,1,1,1,2,2,2,2,0,0,0,1,1,2,3,
					3,0,0,1,1,1,1,1,2,2,2,0,0,0,0,1,1,1,2,3,
					3,0,0,0,0,1,1,1,2,1,1,0,0,0,0,1,1,1,1,3,
					3,1,0,0,0,0,0,0,1,2,0,0,0,0,0,0,1,1,1,3,
					3,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,
					3,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,3,
					3,0,0,0,0,0,0,0,0,1,1,1,1,2,1,1,0,0,0,3,
					3,0,0,0,0,0,1,1,1,1,2,2,2,2,1,1,0,0,0,3,
					3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
				};
				for(int i = 0; i < 20; i++)
					for (int j = 0; j < 20; j++)
					{
						map[i][j] = lvl1[i][j];
					}
				GG.setx(2);
				GG.sety(4);
				Tima1.setx(3);
				Tima1.sety(17);
				Tima2.setx(17);
				Tima2.sety(5);
				Tima3.setx(18);
				Tima3.sety(17);
				Tima4.setx(6);
				Tima4.sety(7);
				Tima5.setx(11);
				Tima5.sety(15);
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num2))
			{
				int lvl2[20][20] =
				{
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
					3,2,2,2,0,0,0,0,2,1,1,1,1,1,1,2,1,1,2,3,
					3,0,0,0,0,0,0,0,0,1,1,2,1,2,2,1,0,0,1,3,
					3,0,0,0,0,2,1,2,0,1,1,1,1,2,1,0,3,0,1,3,
					3,2,0,0,0,1,2,1,0,1,2,1,1,0,3,0,0,0,2,3,
					3,3,3,3,0,0,0,0,0,0,2,0,0,0,3,0,0,2,2,3,
					3,1,1,1,0,0,0,0,0,0,0,0,0,0,2,0,0,1,1,3,
					3,2,1,1,1,0,0,0,0,0,0,1,2,3,0,0,0,1,1,3,
					3,0,0,2,1,1,1,1,2,1,1,0,0,0,0,0,0,1,2,3,
					3,0,0,0,1,1,3,2,1,1,0,0,0,0,0,1,2,3,3,3,
					3,0,0,0,1,1,1,3,1,0,0,0,1,2,1,1,3,1,2,3,
					3,0,0,1,1,1,1,3,1,2,0,1,3,1,1,2,1,1,1,3,
					3,2,3,1,1,1,2,1,1,1,1,2,0,0,0,0,0,0,2,3,
					3,3,1,1,1,1,1,0,1,1,2,0,0,0,0,0,0,0,1,3,
					3,0,2,2,1,2,1,1,0,0,0,0,0,0,0,0,0,0,1,3,
					3,0,0,0,1,1,1,2,1,0,0,0,0,0,0,0,0,0,3,3,
					3,0,0,0,1,2,1,1,1,2,2,0,0,0,0,0,0,2,2,3,
					3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
				};
				for (int i = 0; i < 20; i++)
					for (int j = 0; j < 20; j++)
					{
						map[i][j] = lvl2[i][j];
					}
				GG.setx(2);
				GG.sety(17);
				Tima1.setx(1);
				Tima1.sety(11);
				Tima2.setx(15);
				Tima2.sety(5);
				Tima3.setx(13);
				Tima3.sety(8);
				Tima4.setx(15);
				Tima4.sety(15);
				Tima5.setx(11);
				Tima5.sety(17);
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num3))
			{
				int lvl3[20][20] =
				{
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
					3,2,2,0,0,0,0,2,1,1,1,1,1,1,1,3,1,1,2,3,
					3,2,0,0,0,0,2,2,2,2,2,2,1,1,1,3,1,3,1,3,
					3,0,0,0,0,1,3,3,0,0,0,0,3,3,2,3,1,1,1,3,
					3,0,0,0,1,3,0,0,0,2,2,0,0,0,3,3,3,3,1,3,
					3,0,0,1,3,0,0,0,0,0,0,0,0,0,0,3,2,3,1,3,
					3,0,1,1,3,0,0,0,0,0,0,0,0,0,3,3,1,3,1,3,
					3,1,1,2,0,0,0,0,0,2,2,0,0,3,0,0,2,3,1,3,
					3,1,1,2,0,2,0,0,2,0,0,2,3,0,2,0,2,3,1,3,
					3,1,1,2,0,2,0,0,2,0,0,3,0,0,2,0,2,3,1,3,
					3,1,1,2,0,0,0,0,0,2,3,0,0,0,0,0,2,3,1,3,
					3,1,1,1,3,0,0,0,0,3,0,0,0,0,0,3,1,3,0,3,
					3,1,1,1,3,0,0,0,3,0,0,0,0,0,0,3,1,0,0,3,
					3,1,1,1,1,3,0,3,0,2,2,0,0,0,3,1,0,0,0,3,
					3,1,1,1,1,1,3,3,0,0,0,0,3,3,1,0,0,0,0,3,
					3,3,3,1,1,1,1,1,2,2,2,2,2,2,0,0,0,0,2,3,
					3,0,3,1,1,1,1,1,1,1,1,1,2,0,0,0,0,2,2,3,
					3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
				};
				for (int i = 0; i < 20; i++)
					for (int j = 0; j < 20; j++)
					{
						map[i][j] = lvl3[i][j];
					}
				GG.setx(10);
				GG.sety(10);
				Tima1.setx(2);
				Tima1.sety(4);
				Tima2.setx(17);
				Tima2.sety(17);
				Tima3.setx(10);
				Tima3.sety(8);
				Tima4.setx(8);
				Tima4.sety(12);
				Tima5.setx(11);
				Tima5.sety(12);
				Deathisherebaby = true;
				Death.setx(1);
				Death.sety(18);
				Death.S.setPosition(1 * 50, 18 * 50);
				Death.S.setTextureRect(IntRect(50, 0, 50, 50));
				Start.restart();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Q))
				break;
			window.clear();
			window.draw(BGoffs);
			Text1.setString("Digger");
			Text1.setCharacterSize(200);
			Text1.setFillColor(Color::Red);
			Text1.setPosition(375, 100);
			Text2.setString("     Select a level:\n        1   2   3\n         (Press)\n\n\nPress Q to quite Digger");
			Text2.setCharacterSize(100);
			Text2.setFillColor(Color::White);
			Text2.setPosition(250, 300);
			window.draw(Text1);
			window.draw(Text2);
			window.display();
		}
		GG.setscore(0);
		GG.setLife(true);
		while (true)
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			if ((GG.getLife() == false) || (GG.getscore() == 45))
				break;
			window.clear();
			window.draw(BGs);
			if (Keyboard::isKeyPressed(Keyboard::Q))
				break;
			if (Keyboard::isKeyPressed(Keyboard::R))
				goto Restart;
			Map(*map);
			GG.Move(*map);
			int mv = Move.getElapsedTime().asMilliseconds();
			if (mv > 10)
			{
				Tima1.Move(*map);
				Tima2.Move(*map);
				Tima3.Move(*map);
				Tima4.Move(*map);
				Tima5.Move(*map);
				Move.restart();
			}
			if (Deathisherebaby)
			{
				int st = Start.getElapsedTime().asSeconds();
				if (st > 15)
					Death.Move(*map, GG.getx(), GG.gety());
			}
			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++)
				{
					if ((map[j][i] == 1) && ((i == GG.getx()) && (j == GG.gety())))
						map[j][i] = 0;
					if ((map[j][i] == 2) && ((i == GG.getx()) && (j == GG.gety())))
					{
						GG.setscore(GG.getscore() + 1);
						map[j][i] = 0;
					}
					if ((Tima1.getx() == GG.getx()) && (Tima1.gety() == GG.gety()))
						GG.setLife(false);
					if ((Tima2.getx() == GG.getx()) && (Tima2.gety() == GG.gety()))
						GG.setLife(false);
					if ((Tima3.getx() == GG.getx()) && (Tima3.gety() == GG.gety()))
						GG.setLife(false);
					if ((Tima4.getx() == GG.getx()) && (Tima4.gety() == GG.gety()))
						GG.setLife(false);
					if ((Tima5.getx() == GG.getx()) && (Tima5.gety() == GG.gety()))
						GG.setLife(false);
					if ((Death.getx() == GG.getx()) && (Death.gety() == GG.gety()))
						GG.setLife(false);
				}
			std::ostringstream GGScore;
			GGScore << GG.getscore();
			Text1.setString("Gold:" + GGScore.str() + "/45");
			Text1.setCharacterSize(75);
			Text1.setFillColor(Color::Yellow);
			Text1.setPosition(25, 0);
			window.draw(Text1);

			Text2.setString("Use WASD to move\tCollect all gold ore");
			Text2.setCharacterSize(75);
			Text2.setFillColor(Color::White);
			Text2.setPosition(300, 0);
			window.draw(Text2);
			window.draw(GG.S);
			window.draw(Tima1.S);
			window.draw(Tima2.S);
			window.draw(Tima3.S);
			window.draw(Tima4.S);
			window.draw(Tima5.S);
			if (Deathisherebaby)
				window.draw(Death.S);
			window.display();
		}
		while (true)
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Q))
				break;
			if (Keyboard::isKeyPressed(Keyboard::R))
				goto Restart;
			window.clear();
			window.draw(BGoffs);
			Text2.setCharacterSize(150);
			Text2.setStyle(Text::Bold);
			if (GG.getscore() == 45)
			{
				Text2.setString("You win");
				Text2.setFillColor(Color::Red);
				Text2.setPosition(367, 375);
			}
			else
				if (GG.getLife() == false)
				{
					Text2.setString("You lose");
					Text2.setFillColor(Color::Blue);
					Text2.setPosition(365, 375);
				}
				else
					break;
			Text1.setString("   Press Q to quit Digger\nPress R to go to the menu");
			Text1.setCharacterSize(75);
			Text1.setFillColor(Color::White);
			Text1.setStyle(Text::Bold);
			Text1.setPosition(275, 550);
			window.draw(Text1);
			window.draw(Text2);
			window.display();
		}
		if (Keyboard::isKeyPressed(Keyboard::Q))
			break;
		if (Keyboard::isKeyPressed(Keyboard::R))
			goto Restart;
	};
} 
void Map(int *map)
{
	Texture Blockt;
	Blockt.loadFromFile("Images/Block.png");
	Texture Goldt;
	Goldt.loadFromFile("Images/Gold.png");
	Texture Obst;
	Obst.loadFromFile("Images/Obstacle.png");
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			if (*((int*)map + ((i) * 20) + j) == 1)
			{
				Sprite Blocks;
				Blocks.setTexture(Blockt);
				Blocks.setPosition(j * 50, i * 50);
				window.draw(Blocks);
			}
			if (*((int*)map + ((i) * 20) + j) == 2)
			{
				Sprite Golds;
				Golds.setTexture(Goldt);
				Golds.setPosition(j * 50, i * 50);
				window.draw(Golds);
			}
			if (*((int*)map + ((i) * 20) + j) == 3)
			{
				Sprite Obss;
				Obss.setTexture(Obst);
				Obss.setPosition(j * 50, i * 50);
				window.draw(Obss);
			}
		}
}