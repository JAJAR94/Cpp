#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include <sstream>


// Define the ChartData class to store data for each data point
class ChartData {
public:
    double value;
    std::string label;
    std::string color;
};

// Define the Chart base class to provide the common interface
class Chart {
public:
    virtual void setData(std::vector<ChartData> data) = 0;
    virtual void draw(std::ofstream& output) = 0;

    virtual ~Chart() = 0;
};

Chart::~Chart() = default;

// Define the BarChart class to implement a bar chart
class BarChart : public Chart {
private:
    std::vector<ChartData> m_data;

public:
    // Constructor that initializes the data member
    BarChart() : m_data() {}

    void setData(std::vector<ChartData> data) override {
        // Generate a random color for each data point
        std::random_device rd;  // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator
        std::uniform_int_distribution<int> distr(0, 255); // define the range for each RGB color component

        for (ChartData& dataPoint : data) {
            int r = distr(eng);
            int g = distr(eng);
            int b = distr(eng);
            dataPoint.color = "rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
        }

        m_data = data;
    }

    void draw(std::ofstream& output) override {
        int barSpacing = 25;
        int barWidth = 50;
        int x = 50;
        double maxValue = 0;

        // Find highest bar
        for (ChartData& dataPoint : m_data) {
            if (dataPoint.value >= maxValue) {
                maxValue = dataPoint.value;
            }
        }

        // Calculate the dimensions of the chart
        int chartWidth = m_data.size() * (barWidth + barSpacing) + 150;
        int chartHeight = 600;

        // Write the SVG header and start the chart element
        output << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>" << std::endl;
        output << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << chartWidth << "\" height=\"" << chartHeight << "\">" << std::endl;
        output << "<g transform=\"translate(50, 450)\">" << std::endl;


        // Draw the bars for each data point
        for (ChartData& dataPoint : m_data) {
            int barHeight = (dataPoint.value * 100) / maxValue;
            output << "    <rect x=\"" << x << "\" y=\"" << -barHeight + 30 << "\" width=\"" << barWidth << "\" height=\"" << barHeight << "\" fill=\"" << dataPoint.color << "\"/>" << std::endl;
            output << "    <text x=\"" << x + 15 << "\" y=\"" << -barHeight + 20 << "\">" << dataPoint.value << "</text>" << std::endl;
            output << "    <text x=\"" << 0 << "\" y=\""<< -barHeight + 20 << "\" font-size=\"50%\">" << "-"<< dataPoint.value << "</text>" << std::endl;output << "    <text x=\"" << x + 20 << "\" y=\"" << 45  << "\">" << dataPoint.label << "</text>" << std::endl;
            x += barWidth + barSpacing;
        }

        //Label
        output << "    <text x=\"" << (chartWidth-150) /2 << "\" y=\"" << 60  << "\">" << "Label" << "</text>" << std::endl;
        //Value
        output << "    <text x=\"" << 70 << "\" y=\"" << 10 << "\" transform=\"rotate(270 20,40)\">" << "Value" << "</text>" << std::endl;

        // Draw the line
        //x
        output << "<line x1=\"0\" y1=\"30\" x2=\"" << chartWidth-100 << "\" y2=\"30\" stroke=\"black\" />" << std::endl;
        //y
        output << "<line x1=\"0\" y1=\"30\" x2=\"0\" y2=\"" << -100 << "\" stroke=\"black\" />" << std::endl;
        
        // End the chart element and write the SVG footer
        output << "  </g>" << std::endl;
        output << "</svg>" << std::endl;
    }

};



// Define a function to parse user input and return a vector of ChartData objects
std::vector<ChartData> parseData(std::string input) {
    std::vector<ChartData> result;
    std::map<std::string, double> labelValueMap;

    // Parse the input and fill the label-value map
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        double value = std::stod(token);
        input.erase(0, pos + delimiter.length());

        pos = input.find(delimiter);
        token = input.substr(0, pos);
        std::string label = token;
        input.erase(0, pos + delimiter.length());

        if (labelValueMap.find(label) == labelValueMap.end()) {
            labelValueMap[label] = value;
        }
        else {
            labelValueMap[label] += value;
        }
    }

    // Convert the label-value map to a vector of ChartData objects
    for (const auto& pair : labelValueMap) {
        ChartData dataPoint;
        dataPoint.value = pair.second;
        dataPoint.label = pair.first;
        result.push_back(dataPoint);
    }

    return result;
}


std::string read(std::string filename){

    std::string line, word, content;
    std::fstream file (filename);
	
		while(getline(file, line))
		{
			
 
			std::stringstream str(line);
 
			while(getline(str, word))
				content += word;
	}
    return content;
    
}


// Define the main function to run the program
int main() {
    // Create a BarChart object
    
    BarChart chart;

    //std::cout<<read("../data.csv");
    std::vector<ChartData> data = parseData(read("../data.csv"));
    chart.setData(data);

    // Draw the chart to a file
    std::ofstream output("chart.svg");
    chart.draw(output);
    output.close();

    // return 0;
}