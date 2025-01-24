#include <iostream>
#include <vector>
using namespace std;

struct Note {
    int id;
    string text;
};

vector<Note> notes; // Notizen im Vektor speichern
int nextId = 1; // Automatisch steigende ID

void createNote() {
    Note newNote;
    newNote.id = nextId++;
    cout << "Text eingeben: ";
    cin.ignore();
    getline(cin, newNote.text);
    notes.push_back(newNote);
    cout << "Notiz wurde hinzugefügt!\n";
}

void displayNotes() {
    if(notes.empty()) {
        cout << "Keine Notizen vorhanden.\n";
        return;
    }
    cout << "\n*-*-*-*-- Notizen --*-*-*-*\n";
    for(const auto& note : notes) {
        cout << "ID: " << note.id << " | Text: " << note.text << "\n";
    }
}

void editNote() {
    int id;
    cout << "Bitte gib die ID der zu berarbeitenden Notiz ein: ";
    cin >> id;

    for(auto& note : notes) {
        if(note.id == id) {
            cout << "Aktueller Text: " << note.text << "\n";
            cout << "Neuer Text: ";
            cin.ignore();
            getline(cin, note.text);
            cout << "Notiz wurde aktualisiert.\n";
            return;
        }
    }
    cout << "Notiz mit der ID " << id << " wurde nicht gefunden.\n";
}

void deleteNote() {
    int id;
    cout << "Bitte gib die ID der zu löschenden Notiz ein: ";
    cin >> id;

    for(auto del = notes.begin(); del != notes.end(); ++del) {
        if(del->id == id) {
            notes.erase(del);
            cout << "Notiz wurde erfolgreich gelöscht.\n";
            return;
        }
    }
    cout << "Notiz mit der ID " << id << " wurde nicht gefunden.\n";
}

void menu() {
        cout << "\n*-*-*-*-- Notiz-Programm --*-*-*-*\n"
             << "1) Notiz erstellen\n"
             << "2) Notizen anzeigen\n"
             << "3) Notiz bearbeiten\n"
             << "4) Notiz löschen\n"
             << "5) Programm beenden\n"
             << "Wähle eine Option: ";
}

int main() {
    int choice;

    do {
        menu();
        cin >> choice;
        switch(choice) {
            case 1: createNote(); break;
            case 2: displayNotes(); break;
            case 3: editNote(); break;
            case 4: deleteNote(); break;
            case 5: cout << "Programm beendet.\n"; break;
            default: cout << "Ungültige Eingabe.\n";
        }
    } while(choice != 5);
    return 0;
}