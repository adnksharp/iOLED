#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire, -1);

class Display 
{
    public:
        void Clear();
        void Print();
        void Begin();
        void SetText(String text, byte x, byte y, byte size);
};

void Display::Clear()
{
    display.clearDisplay();
}

void Display::Print()
{
    display.display();
}

void Display::SetText(String text, byte x, byte y, byte size)
{
    display.setTextSize(size);
    display.setCursor(x, y);
    display.print(text);
}

void Display::Begin()
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
        for(;;);
    display.setTextColor(WHITE);
    Display::Clear();
    Display::SetText("Sistema iniciado", 0, 0, 1);
    Display::Print();
}
