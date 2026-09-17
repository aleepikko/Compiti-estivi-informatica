#include <iostream>
using namespace std;
#include <fstream>
#define MAX 100

// Aggiungere numeri
void aggiungiNumeri(int vettore[], int &totale) {

    int quanti;

    cout << "\nQuanti numeri vuoi aggiungere? ";
    cin >> quanti;

    for (int i = 0; i < quanti; i++) {

        if (totale >= MAX) {
            cout << "Spazio esaurito!" << endl;
            return;
        }

        cout << "Inserisci numero: ";
        cin >> vettore[totale];

        totale++;
    }

    cout << "Numeri aggiunti con successo!" << endl;
}


// Visualizzare il vettore
void visualizzaNumeri(int vettore[], int totale) {

    if (totale == 0) {
        cout << "Il vettore e' vuoto." << endl;
        return;
    }

    cout << "\n--- NUMERI NEL VETTORE ---\n";

    for (int i = 0; i < totale; i++) {

        cout << "Posizione " << i
             << ": " << vettore[i] << endl;
    }
}


// Salvare i numeri su un file
void salvaSuFile(int vettore[], int totale) {

    ofstream file("numeri.txt");

    if (!file) {
        cout << "Errore nell'apertura del file." << endl;
        return;
    }

    for (int i = 0; i < totale; i++) {

        file << vettore[i] << endl;
    }

    file.close();

    cout << "Numeri salvati su file con successo." << endl;
}


// Leggere i numeri da un file
void leggiFile(int vettore[], int &totale) {

    ifstream file("numeri.txt");

    if (!file) {
        cout << "Errore nell'apertura del file." << endl;
        return;
    }

    totale = 0;

    while (file >> vettore[totale]) {

        totale++;

        if (totale >= MAX) {
            cout << "Limite massimo raggiunto." << endl;
            break;
        }
    }

    file.close();

    cout << "Numeri caricati da file con successo." << endl;
}


// Calcolare minimo, massimo, somma e media
void calcolaStatistiche(int vettore[], int totale) {

    if (totale == 0) {
        cout << "Il vettore e' vuoto." << endl;
        return;
    }

    int minimo = vettore[0];
    int massimo = vettore[0];
    int somma = 0;
    float media;

    for (int i = 0; i < totale; i++) {

        somma += vettore[i];

        if (vettore[i] < minimo) {
            minimo = vettore[i];
        }

        if (vettore[i] > massimo) {
            massimo = vettore[i];
        }
    }

    media = (float)somma / totale;

    cout << "\n--- STATISTICHE ---" << endl;

    cout << "Minimo: " << minimo << endl;
    cout << "Massimo: " << massimo << endl;
    cout << "Somma: " << somma << endl;
    cout << "Media: " << media << endl;
}


// Trovare posizioni del minimo e del massimo
void posizioneMinMax(int vettore[], int totale) {

    if (totale == 0) {
        cout << "Il vettore è vuoto." << endl;
        return;
    }

    int posizioneMin = 0;
    int posizioneMax = 0;

    for (int i = 1; i < totale; i++) {

        if (vettore[i] < vettore[posizioneMin]) {
            posizioneMin = i;
        }

        if (vettore[i] > vettore[posizioneMax]) {
            posizioneMax = i;
        }
    }

    cout << "Posizione del minimo: "
         << posizioneMin << endl;

    cout << "Posizione del massimo: "
         << posizioneMax << endl;
}


// Contare i numeri compresi tra due valori
void contaIntervallo(int vettore[], int totale) {

    int a, b;
    int contatore = 0;

    cout << "Inserisci il primo numero: ";
    cin >> a;

    cout << "Inserisci il secondo numero: ";
    cin >> b;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int i = 0; i < totale; i++) {

        if (vettore[i] >= a && vettore[i] <= b) {
            contatore++;
        }
    }

    cout << "Numeri compresi tra "
         << a << " e " << b << ": "
         << contatore << endl;
}


// Sostituire un numero
void sostituisciNumeri(int vettore[], int totale) {

    int vecchio, nuovo;
    int sostituzioni = 0;

    cout << "Numero da sostituire: ";
    cin >> vecchio;

    cout << "Nuovo numero: ";
    cin >> nuovo;

    for (int i = 0; i < totale; i++) {

        if (vettore[i] == vecchio) {

            vettore[i] = nuovo;

            sostituzioni++;
        }
    }

    cout << "Sostituzioni effettuate: "
         << sostituzioni << endl;
}


// Cercare numero
int cercaNumero(int vettore[], int totale, int numero) {

    for (int i = 0; i < totale; i++) {

        if (vettore[i] == numero) {
            return i;
        }
    }

    return -1;
}


// Modificare numero data la posizione
void modificaPosizione(int vettore[], int totale) {

    int posizione;
    int nuovoNumero;

    cout << "Inserisci la posizione: ";
    cin >> posizione;

    if (posizione < 0 || posizione >= totale) {

        cout << "Posizione non valida." << endl;
        return;
    }

    cout << "Inserisci il nuovo numero: ";
    cin >> nuovoNumero;

    vettore[posizione] = nuovoNumero;

    cout << "Numero modificato con successo." << endl;
}


// Modificare numero data la posizione
void modificaValore(int vettore[], int totale) {

    int vecchio, nuovo;
    bool trovato = false;

    cout << "Numero da modificare: ";
    cin >> vecchio;

    cout << "Nuovo numero: ";
    cin >> nuovo;

    for (int i = 0; i < totale; i++) {

        if (vettore[i] == vecchio) {

            vettore[i] = nuovo;
            trovato = true;
        }
    }

    if (trovato) {
        cout << "Numeri modificati con successo." << endl;
    } else {
        cout << "Numero non trovato." << endl;
    }
}


// Cancellare un numero data la posizione
void cancellaPosizione(int vettore[], int &totale) {

    int posizione;

    cout << "Inserisci la posizione da cancellare: ";
    cin >> posizione;

    if (posizione < 0 || posizione >= totale) {

        cout << "Posizione non valida." << endl;
        return;
    }

    for (int i = posizione; i < totale - 1; i++) {

        vettore[i] = vettore[i + 1];
    }

    totale--;

    cout << "Numero cancellato con successo." << endl;
}


// Cancellare un numero dato il valore
void cancellaValore(int vettore[], int &totale) {

    int numero;
    bool trovato = false;

    cout << "Inserisci il numero da cancellare: ";
    cin >> numero;

    for (int i = 0; i < totale; i++) {

        if (vettore[i] == numero) {

            for (int j = i; j < totale - 1; j++) {

                vettore[j] = vettore[j + 1];
            }

            totale--;
            i--;

            trovato = true;
        }
    }

    if (trovato) {
        cout << "Numeri cancellati con successo." << endl;
    } else {
        cout << "Numero non trovato." << endl;
    }
}


// Ordinare il vettore
void ordinaVettore(int vettore[], int totale) {

    for (int i = 0; i < totale - 1; i++) {

        for (int j = 0; j < totale - i - 1; j++) {

            if (vettore[j] > vettore[j + 1]) {

                int temp = vettore[j];

                vettore[j] = vettore[j + 1];

                vettore[j + 1] = temp;
            }
        }
    }

    cout << "Vettore ordinato con successo." << endl;
}


// Inserimento in ordine
void inserisciInOrdine(int vettore[], int &totale) {

    int numero;
    int posizione = 0;

    if (totale >= MAX) {

        cout << "Spazio esaurito." << endl;
        return;
    }

    cout << "Inserisci un numero: ";
    cin >> numero;

    while (posizione < totale &&
           vettore[posizione] < numero) {

        posizione++;
    }

    for (int i = totale; i > posizione; i--) {

        vettore[i] = vettore[i - 1];
    }

    vettore[posizione] = numero;

    totale++;

    cout << "Numero inserito in ordine." << endl;
}

int main() {

    int vettore[MAX];
    int totale = 0;
    int scelta;
    int numero;
    int posizione;

    do {

        cout << "\n========== MENU ==========" << endl;

        cout << "1. Aggiungi numeri" << endl;
        cout << "2. Visualizza numeri" << endl;
        cout << "3. Salva su file" << endl;
        cout << "4. Leggi da file" << endl;
        cout << "5. Calcola statistiche" << endl;
        cout << "6. Posizione minimo e massimo" << endl;
        cout << "7. Conta valori in un intervallo" << endl;
        cout << "8. Sostituisci numeri" << endl;
        cout << "9. Cerca un numero" << endl;
        cout << "10. Modifica per posizione" << endl;
        cout << "11. Modifica per valore" << endl;
        cout << "12. Cancella per posizione" << endl;
        cout << "13. Cancella per valore" << endl;
        cout << "14. Ordina vettore" << endl;
        cout << "15. Inserimento in ordine" << endl;
        cout << "0. Esci" << endl;

        cout << "\nInserisci la scelta: ";
        cin >> scelta;

        switch (scelta) {

            case 1:
                aggiungiNumeri(vettore, totale);
                break;

            case 2:
                visualizzaNumeri(vettore, totale);
                break;

            case 3:
                salvaSuFile(vettore, totale);
                break;

            case 4:
                leggiFile(vettore, totale);
                break;

            case 5:
                calcolaStatistiche(vettore, totale);
                break;

            case 6:
                posizioneMinMax(vettore, totale);
                break;

            case 7:
                contaIntervallo(vettore, totale);
                break;

            case 8:
                sostituisciNumeri(vettore, totale);
                break;

            case 9:

                cout << "Inserisci il numero da cercare: ";
                cin >> numero;

                posizione = cercaNumero(
                    vettore, totale, numero
                );

                cout << "Posizione: "
                     << posizione << endl;

                break;

            case 10:
                modificaPosizione(vettore, totale);
                break;

            case 11:
                modificaValore(vettore, totale);
                break;

            case 12:
                cancellaPosizione(vettore, totale);
                break;

            case 13:
                cancellaValore(vettore, totale);
                break;

            case 14:
                ordinaVettore(vettore, totale);
                break;

            case 15:
                inserisciInOrdine(vettore, totale);
                break;

            case 0:
                cout << "Uscita dal programma..." << endl;
                break;

            default:
                cout << "Scelta non valida." << endl;
        }

    } while (scelta != 0);

    return 0;
}