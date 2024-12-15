#include "algo.hpp"
#include <iomanip>
#include <stdarg.h>
#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace algo;

bool drawGraph(vector<double> &xs, vector<double> &ys, const string &file_name)
{
	bool success;
	StringReference *errorMessage = new StringReference();
	RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->lineThickness = 2.0;
	series->xs = &xs;
	series->ys = &ys;

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 800;
	settings->height = 600;
	settings->autoBoundaries = false;
	settings->xMax = GetMaximum(&xs);
	settings->yMax = GetMaximum(&ys);
	settings->autoPadding = true;
	settings->title = toVector(L"Array Length (N) v/s Comparisons (C)");
	settings->xLabel = toVector(L"N");
	settings->yLabel = toVector(L"C");
	settings->scatterPlotSeries->push_back(series);

	success = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);
	// success = DrawScatterPlot(imageReference, 1024, 768, &xs, &ys, errorMessage);

	if (success)
	{
		vector<double> *pngdata = ConvertToPNG(imageReference->image);
		WriteToFile(pngdata, file_name);
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
	return success;
}

void random_array_sim(const uint &begin, const uint &stop, const uint &n, vector<double> &length, vector<double> *comparison)
{
	if (begin >= stop || n <= 0)
		return;

	uint len, arr[stop];

	for (uint i = 0; i < n; i++)
	{
		srand(stop + begin * i);
		len = begin + rand() % (stop - begin + 1);
		length.push_back(len);

		// Random Array Generation
		for (uint j = 0; j < len; j++)
			arr[j] = i + j + rand() % (len + n * j);

		comparison[0].push_back(insertionSort(arr, len));

		// For randomness
		for (uint j = 0; j < len; j += rand() % len / 8)
			swap(&arr[j], &arr[(i + j) % len]);

		comparison[1].push_back(mergeSort(arr, 0, len - 1));

		for (uint j = 0; j < len; j += rand() % len / 8)
			swap(&arr[j], &arr[(i + j) % len]);

		comparison[2].push_back(heapSort(arr, len, greater<int>()));

		for (uint j = 0; j < len; j += rand() % len / 8)
			swap(&arr[j], &arr[(i + j) % len]);

		comparison[3].push_back(random_quickSort(arr, 0, len - 1));
	}
}

int main()
{
	vector<double> lens, cmps[4];
	string names[] = {"InsertionSort.png", "MergeSort.png", "HeapSort.png", "Random_QuickSort.png"};
	random_array_sim(30, 1000, 100, lens, cmps);

	for (int i = 0; i < 4; i++)
		cout << boolalpha << "\n Creation of " << left << setw(25)
			 << names[i] << " : " << drawGraph(lens, cmps[i], names[i]);
}