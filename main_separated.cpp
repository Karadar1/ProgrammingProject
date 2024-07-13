#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "AgriculturalSurfaceManager.h"

using namespace std;

int main()
{
    AgriculturalSurfaceManager manager;

    int option;

    do
    {
        cout << endl;
        cout << "1. Add agricultural surface" << endl;
        cout << "2. Remove agricultural surface" << endl;
        cout << "3. Edit agricultural surface" << endl;
        cout << "4. Show agricultural surfaces " << endl;
        cout << endl;
        cout << "5. Add production" << endl;
        cout << "6. Remove production" << endl;
        cout << "7. Edit production" << endl;
        cout << "8. Show production" << endl;
        cout << endl;
        cout << "9. Show total production per plant type" << endl;

        cout << "0. Exit" << endl;

        cout << "Enter option: ";

        cin >> option;

        if (option == 1)
        {
            string name;
            string plantType;
            float surface;

            cout << endl;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);

            cout << endl;
            cout << "Enter plant type: ";
            cin >> plantType;

            cout << endl;
            cout << "Enter surface: ";
            cin >> surface;

            AgriculturalSurface agriculturalSurface;
            agriculturalSurface.name = name;
            agriculturalSurface.plantType = plantType;
            agriculturalSurface.surface = surface;

            manager.addSurface(agriculturalSurface);
        }
        else if (option == 2)
        {
            if (manager.surfaces.size() == 0)
            {
                cout << "No surfaces to remove" << endl;
                continue;
            }

            string name;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);

            manager.removeSurface(name);
        }
        else if (option == 3)
        {
            if (manager.surfaces.size() == 0)
            {
                cout << "No surfaces to edit" << endl;
                continue;
            }

            string name;
            string newName;
            string plantType;
            float surface;

            cout << endl;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);

            cout << endl;
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, newName);

            cout << endl;
            cout << "Enter plant type: ";
            cin >> plantType;

            cout << endl;
            cout << "Enter surface (ha): ";
            cin >> surface;

            AgriculturalSurface agriculturalSurface;
            agriculturalSurface.name = newName;
            agriculturalSurface.plantType = plantType;
            agriculturalSurface.surface = surface;

            manager.editSurface(name, agriculturalSurface);
        }
        else if (option == 4)
        {
            manager.showSurfaces();
        }
        else if (option == 5)
        {
            if (manager.surfaces.size() == 0)
            {
                cout << "No surfaces to add production" << endl;
                continue;
            }

            string surfaceName;
            float quantity;
            float period;

            cout << endl;
            cout << "Enter surface name: ";
            cin.ignore();
            getline(cin, surfaceName);

            cout << endl;
            cout << "Enter quantity (kg): ";
            cin >> quantity;

            cout << endl;
            cout << "Enter period (days): ";
            cin >> period;

            Production production;
            production.productionId = manager.productions.size() + 1;
            production.surfaceName = surfaceName;
            production.quantity = quantity;
            production.period = period;

            manager.addProduction(production);
        }
        else if (option == 6)
        {
            if (manager.productions.size() == 0)
            {
                cout << "No productions to remove" << endl;
                continue;
            }

            int productionId;
            cout << "Enter production ID: ";
            cin >> productionId;

            manager.removeProduction(productionId);
        }
        else if (option == 7)
        {
            if (manager.productions.size() == 0)
            {
                cout << "No productions to edit" << endl;
                continue;
            }

            int productionId;
            string surfaceName;
            float quantity;
            float period;

            cout << endl;
            cout << "Enter production ID: ";
            cin >> productionId;

            cout << endl;
            cout << "Enter surface name: ";
            cin.ignore();
            getline(cin, surfaceName);

            cout << endl;
            cout << "Enter quantity (kg): ";
            cin >> quantity;

            cout << endl;
            cout << "Enter period (days): ";
            cin >> period;

            Production production;
            production.productionId = productionId;
            production.surfaceName = surfaceName;
            production.quantity = quantity;
            production.period = period;

            manager.editProduction(productionId, production);
        }
        else if (option == 8)
        {
            manager.showProductions();
        }
        else if (option == 9)
        {
            manager.showTotalProductionPerPlantType();
        }
    } while (option != 0);

    return 0;
};
