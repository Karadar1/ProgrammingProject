#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class AgriculturalSurface
{
public:
    string name;
    string plantType;
    float surface;
};

class Production
{
public:
    int productionId;
    string surfaceName;
    float quantity;
    float period;
};

class AgriculturalSurfaceManager
{
public:
    vector<AgriculturalSurface> surfaces;
    vector<Production> productions;

    void addSurface(AgriculturalSurface surface)
    {
        for (int i = 0; i < surfaces.size(); i++)
        {
            if (surfaces[i].name == surface.name)
            {
                cout << "Surface '" << surface.name << "' already exists" << endl;
                return;
            };
        };

        surfaces.push_back(surface);
        cout << "Surface '" << surface.name << "' added" << endl;
    };

    void removeSurface(string name)
    {
        for (int i = 0; i < surfaces.size(); i++)
        {
            if (surfaces[i].name == name)
            {
                surfaces.erase(surfaces.begin() + i);
                cout << "Surface '" << name << "' removed" << endl;
                break;
            };
        };

        cout << "Surface '" << name << "' not found" << endl;
    };

    void editSurface(string name, AgriculturalSurface newSurface)
    {
        for (int i = 0; i < surfaces.size(); i++)
        {
            if (surfaces[i].name == name)
            {
                surfaces[i] = newSurface;
                cout << "Surface '" << name << "' edited" << endl;
                break;
            };
        };

        cout << "Surface '" << name << "' not found" << endl;
    };

    void showSurfaces()
    {
        cout << endl;
        cout << "Agricultural surfaces: " << endl;

        for (int i = 0; i < surfaces.size(); i++)
        {
            cout << endl;
            cout << "Name: " << surfaces[i].name << endl;
            cout << "Plant type: " << surfaces[i].plantType << endl;
            cout << "Surface: " << surfaces[i].surface << "ha" << endl;
            cout << endl;
        }
    };

    void addProduction(Production production)
    {
        for (int i = 0; i < surfaces.size(); i++)
        {
            if (surfaces[i].name == production.surfaceName)
            {
                productions.push_back(production);
                cout << "Production of '" << surfaces[i].plantType << "' with " << production.quantity << " kg" << " in " << production.period << " days added" << endl;
                return;
            };
        };

        cout << "Surface '" << production.surfaceName << "' not found" << endl;
    };

    void removeProduction(int productionId)
    {
        for (int i = 0; i < productions.size(); i++)
        {
            if (productions[i].productionId == productionId)
            {
                productions.erase(productions.begin() + i);
                cout << "Production with ID " << productionId << " removed" << endl;
                break;
            };
        };

        cout << "Production with ID " << productionId << " not found" << endl;
    };

    void editProduction(int productionId, Production newProduction)
    {
        for (int i = 0; i < productions.size(); i++)
        {
            if (productions[i].productionId == productionId)
            {
                productions[i] = newProduction;
                cout << "Production with ID " << productionId << " edited" << endl;
                break;
            };
        };

        cout << "Production with ID " << productionId << " not found" << endl;
    };

    void showProductions()
    {
        cout << endl;
        cout << "Productions: " << endl;

        for (int i = 0; i < productions.size(); i++)
        {
            cout << endl;
            cout << "ID: " << productions[i].productionId << endl;
            cout << "Surface name: " << productions[i].surfaceName << endl;
            cout << "Quantity: " << productions[i].quantity << " kg" << endl;
            cout << "Period: " << productions[i].period << " days" << endl;
            cout << endl;
        }
    }

    void showTotalProductionPerPlantType()
    {
        cout << endl;
        cout << "Total production per plant type: " << endl;

        vector<string> plantTypes;

        for (int i = 0; i < surfaces.size(); i++)
        {
            if (find(plantTypes.begin(), plantTypes.end(), surfaces[i].plantType) == plantTypes.end())
            {
                plantTypes.push_back(surfaces[i].plantType);
            };
        };

        if (plantTypes.size() == 0)
        {
            cout << "No plant types found" << endl;
            return;
        };

        for (int i = 0; i < plantTypes.size(); i++)
        {
            float totalProduction = 0;
            float totalSurface = 0;
            float totalPeriod = 0;

            for (int j = 0; j < surfaces.size(); j++)
            {
                if (surfaces[j].plantType == plantTypes[i])
                {
                    for (int k = 0; k < productions.size(); k++)
                    {
                        if (productions[k].surfaceName == surfaces[j].name)
                        {
                            totalProduction += productions[k].quantity;
                            totalSurface += surfaces[j].surface;
                            totalPeriod += productions[k].period;
                        };
                    };
                };
            };

            cout << endl;
            cout << "Plant type: " << plantTypes[i] << endl;
            cout << "Total production: " << totalProduction << " kg" << endl;
            cout << "Total surface: " << totalSurface << " ha" << endl;
            cout << "Total period: " << totalPeriod << " days" << endl;
            cout << "Average production: " << 1 << " kg / " << totalSurface / totalProduction << " ha / " << totalPeriod / totalProduction << " days" << endl;

            cout << endl;
        };
    };
};

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
