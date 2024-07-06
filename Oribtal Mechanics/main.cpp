#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>

// Function to create a text object
sf::Text createText(const std::string& string, const sf::Font& font, unsigned int size, sf::Color color, sf::Vector2f position) {
    sf::Text text;
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
    return text;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Orbital Mechanics Emulator");

    // Load font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }

    // Layout Elements
    // Header
    sf::Text header = createText("Orbital Mechanics Emulator", font, 24, sf::Color::White, sf::Vector2f(10, 10));

    // Footer
    sf::Text footer = createText("Developed by [Your Name]", font, 14, sf::Color::White, sf::Vector2f(10, 690));

    // Visualization Panel (Placeholder)
    sf::RectangleShape visualizationPanel(sf::Vector2f(960, 540));
    visualizationPanel.setPosition(10, 50);
    visualizationPanel.setFillColor(sf::Color(50, 50, 50));

    // Control Panel (Placeholder)
    sf::RectangleShape controlPanel(sf::Vector2f(290, 540));
    controlPanel.setPosition(980, 50);
    controlPanel.setFillColor(sf::Color(70, 70, 70));

    // Simulation Controls (Placeholders)
    sf::Text playButton = createText("Play", font, 18, sf::Color::White, sf::Vector2f(990, 60));
    sf::Text pauseButton = createText("Pause", font, 18, sf::Color::White, sf::Vector2f(990, 100));
    sf::Text resetButton = createText("Reset", font, 18, sf::Color::White, sf::Vector2f(990, 140));
    sf::Text stepButton = createText("Step", font, 18, sf::Color::White, sf::Vector2f(990, 180));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw layout elements
        window.draw(header);
        window.draw(footer);
        window.draw(visualizationPanel);
        window.draw(controlPanel);

        // Draw control buttons
        window.draw(playButton);
        window.draw(pauseButton);
        window.draw(resetButton);
        window.draw(stepButton);

        window.display();
    }

    return 0;
}
