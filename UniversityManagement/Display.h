#pragma once
class Display
{
public:
	Display(const char* color);
	virtual ~Display();
	void SetFontSize(int y, const char* bc);
	void WindowSize(int height,int width);
	void DisplayBar(float value);
	void WindowMax();
	void StartScreen(Display d1);	
};
void displayBar(float value);
void SetColor(int x);
string EnterPassword(const string& prompt = "Enter password> ");

