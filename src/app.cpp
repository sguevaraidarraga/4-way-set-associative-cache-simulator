#include "app.h"

App::App() : cpu() {}
bool App::mainMenu() {
    bool f = false;
    int cmd;
    cout << endl
         << "-------------------------------------------------" << endl
         << "1. Inicializar DRAM" << endl
         << "2. Ejecutar instrucciones desde archivo" << endl
         << "3. Generar instrucciones aleatoriamente" << endl
         << "4. Imprimir cache" << endl
         << "5. Exportar archivos" << endl
         << "6. Salir" << endl
         << "-------------------------------------------------" << endl;
    cin >> cmd;
    cout << endl;
    try {
        switch(cmd) {
            case 1:
                initializeDRAMMenu();
                break;
            case 2:
                executeFromFile();
                break;
            case 3:
                generateInstructions();
                break;
            case 4:
                printCache();
                break;
            case 5:
                exportFiles();
                break;
            case 6:
                f = true;
                break;
        }
    } catch(const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return f;
}
void App::initializeDRAMMenu() {
    int cmd;
    cout << endl
         << "-------------------------------------------------" << endl
         << "1. Cargar DRAM desde archivo" << endl
         << "2. Inicializar DRAM aleatoriamente" << endl
         << "3. Atras" << endl
         << "-------------------------------------------------" << endl;
    cin >> cmd;
    try {
        switch(cmd) {
            case 1:
                initializeDRAMFromFile();
                break;
            case 2:
                generateDRAM();
                break;
        }
    } catch(const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}
void App::initializeDRAMFromFile() {
    string filename;
    cout << "Por favor, coloque el archivo de entrada dentro de la carpeta 'files' del proyecto." << endl
         << "Luego, escriba el nombre y la extension del archivo (por ejemplo: example.txt): ";
    cin >> filename;
    cout << endl;
    try {
        cpu.loadDRAMFromFile(Constants::FILES_PATH + filename);
        cout << "DRAM cargada correctamente." << endl;
    } catch(const exception &e) {
        cout << "Error al cargar DRAM: " << e.what() << endl;
    }
}
void App::executeFromFile() {
    string filename;
    cout << "Por favor, coloque el archivo de instrucciones dentro de la carpeta 'files' del proyecto." << endl
         << "Luego, escriba el nombre y la extension del archivo (por ejemplo: instrucciones.txt): ";
    cin >> filename;
    cout << endl;
    try {
        FileManager::executeInstructionsFromFile(cpu, filename);
        cout << "Instrucciones ejecutadas correctamente." << endl;
    } catch(const exception &e) {
        cout << "Error al ejecutar instrucciones: " << e.what() << endl;
    }
}
void App::generateInstructions() {
    unsigned int k;
    cout << "Escriba el numero de instrucciones aleatorias: " << endl;
    cin >> k;
    cout << endl;
    try {
        Generator::generateInstructions(cpu, k);
        cout << "Instrucciones generadas correctamente." << endl;
    } catch(const exception &e) {
        cout << "Error al generar instrucciones: " << e.what() << endl;
    }
}
void App::printCache() {
    cpu.printCache();
    cout << endl;
}
void App::exportFiles() {
    cpu.generateDRAMFile();
    FileManager::generateLogFile();
}