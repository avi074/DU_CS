#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace std;

int main()
{
    bool success;
    StringReference *errorMessage = new StringReference();
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

    vector<double> xs;
    vector<double> ys;

    for (int i = 1; i <= 1000; i += 10)
    {
        xs.push_back(i);
        ys.push_back(i * log2(i));
    }

    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
    series->xs = &xs;
    series->ys = &ys;
    series->linearInterpolation = true;
    series->lineType = toVector(L"dotted");
    series->lineThickness = 2;
    series->color = GetGray(0.3);

    ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
    settings->width = 600;
    settings->height = 400;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    settings->title = toVector(L"NlogN");
    settings->xLabel = toVector(L"X axis (N)");
    settings->yLabel = toVector(L"Y axis");
    settings->scatterPlotSeries->push_back(series);

    success = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

    if (success)
    {
        vector<double> *pngdata = ConvertToPNG(imageReference->image);
        WriteToFile(pngdata, "example2.png");
        DeleteImage(imageReference->image);
    }
    else
    {
        cerr << "Error: ";
        for (wchar_t c : *errorMessage->string)
        {
            wcerr << c;
        }
        cerr << endl;
    }

    return success ? 0 : 1;
}