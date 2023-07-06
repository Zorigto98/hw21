#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct village // поселок
{
    float square_village = 0;
    int amount_plot = 0;

};

struct plot // участок
{
    int num_plot = 0;
    float square_plot = 0;
    int builds = 0;
};

struct building // здание
{
    string name_building = "unknown";
    enum type_building
    {
        house, garage, bath, extension
    };
    float square_building = 0;
    bool heating = false;
    struct floor
    {
        int num_floor = 1;
        float height_floor = 0;
        vector <string> name_room;
    }floor;

};


int main ()
{
    village Moscow;

    int square_vill, am_plot;
    cout << "Input square of village: " << endl;
    cin >>  square_vill;
    Moscow.square_village = square_vill;

    cout << "Input amount plot in village: " << endl;
    cin >>  am_plot;
    Moscow.amount_plot = am_plot;

    plot plot[am_plot];

    for (int p = 1; p <= am_plot; p++)  // заполненеи информации об участке
    {
        plot[p].num_plot = p; // номер участка, присваивается по порядку

        float sqr_plot; // площадь участка
        cout << "input square plot #" << p << endl;
        cin >> sqr_plot;
        plot[p].square_plot = sqr_plot;

        int builds; // колличество участков
        cout << "Input amount building in plot #" << p << endl;
        cin >> builds;
        plot[p].builds = builds;

        building building[builds];

        for (int b = 1; b <= builds; b++) // заполнение информации о здании
        {
            string type_build; // название здания
            cout << "input name of build " << b << endl;
            cin >> type_build;
            building[b].name_building = type_build;

            float build_sqr; // площадь здания
            cout << "Input square " << building[b].name_building << endl;
            cin >> build_sqr;
            building[b].square_building = build_sqr;

            char heating; // отопление в здании
            cout << building[b].name_building << " have a heating?" << endl;
            cout << "y - with heating || n - without heating" << endl;
            cin >> heating;
            if (heating == 'y') building[b].heating = true;
            else building[b].heating = false;

            int floor;
            cout << "How many floors in build?" << endl;
            cin >> floor;

            for (int f=1; f <= floor; f ++)
            {
                building[b].floor.num_floor = f; // заполнение информации об этаже

                float height_floor;
                cout << "Input height floor in " <<  building[b].name_building << endl;
                cin >> height_floor;
                building[b].floor.height_floor = height_floor;

                cout << "How many rooms in " << building[b].name_building << " " << f << " floor" << endl;
                int room;
                cin >> room;
                for (int r = 1; r <= room; r++)
                {
                    cout << "Input " << r << " room in " << f << " floor" << endl;
                    string str_room;
                    cin >> str_room;
                    building[b].floor.name_room.push_back(str_room);
                }
            }
        }
    }
}