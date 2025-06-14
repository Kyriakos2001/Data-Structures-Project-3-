# Question4

Graph.h
Edge: Αυτή η δομή αναπαριστά μια ακμή του γράφου και περιλαμβάνει το βάρος (weight), τον προορισμό (dest) και έναν δείκτη (next) που δείχνει στην επόμενη ακμή.
Graph: Αυτή η δομή αναπαριστά τον γράφο και περιλαμβάνει τον αριθμό των κορυφών (numVertices) και τις λίστες γειτνίασης (adjLists).
Stack: Αυτή η δομή αναπαριστά μια στοίβα και περιλαμβάνει έναν πίνακα στοιχείων (items) και έναν δείκτη κορυφής (top).
Δηλώσεις Συναρτήσεων:

createGraph: Δημιουργεί και αρχικοποιεί έναν νέο γράφο με δοθέντα αριθμό κορυφών.
createEdge: Δημιουργεί και αρχικοποιεί μια νέα ακμή με δοθέν προορισμό και βάρος.
addEdge: Προσθέτει μια ακμή στον γράφο.
topologicalSortUtil: Βοηθητική συνάρτηση για την τοπολογική ταξινόμηση, χρησιμοποιώντας DFS.
topologicalSort: Υπολογίζει την τοπολογική ταξινόμηση του γράφου.
shortestPath: Υπολογίζει τα συντομότερα μονοπάτια από μια αφετηρία προς όλους τους άλλους κόμβους του γράφου.
createStack: Δημιουργεί και αρχικοποιεί μια νέα στοίβα.
push: Προσθέτει ένα στοιχείο στη στοίβα.
pop: Αφαιρεί και επιστρέφει το στοιχείο από την κορυφή της στοίβας.
isEmpty: Ελέγχει αν η στοίβα είναι κενή.

Graph.c
Υλοποίηση των συναρτήσεων που δηλώθηκαν στο Graph.h:

createGraph: Δημιουργεί έναν νέο γράφο και αρχικοποιεί τις λίστες γειτνίασης σε NULL.
createEdge: Δημιουργεί μια νέα ακμή και αρχικοποιεί το βάρος και τον προορισμό της.
addEdge: Προσθέτει μια ακμή στη λίστα γειτνίασης του γράφου.
topologicalSortUtil: Εκτελεί DFS για την τοπολογική ταξινόμηση και προσθέτει τις κορυφές στη στοίβα.
topologicalSort: Υπολογίζει την τοπολογική ταξινόμηση του γράφου, αρχικοποιώντας τον πίνακα visited και καλώντας τη topologicalSortUtil.
shortestPath: Υπολογίζει τα συντομότερα μονοπάτια χρησιμοποιώντας την τοπολογική ταξινόμηση για την εύρεση της σειράς των κόμβων και ενημερώνει τις αποστάσεις των κορυφών.
createStack: Δημιουργεί μια νέα στοίβα και αρχικοποιεί τον δείκτη κορυφής σε -1.
push: Προσθέτει ένα στοιχείο στη στοίβα.
pop: Αφαιρεί και επιστρέφει το στοιχείο από την κορυφή της στοίβας.
isEmpty: Ελέγχει αν η στοίβα είναι κενή.

main.c
Η κύρια συνάρτηση που επιδεικνύει τη λειτουργικότητα των παραπάνω συναρτήσεων:

Δημιουργεί έναν νέο γράφο με δοσμένο αριθμό κορυφών.
Προσθέτει ακμές με βάρη στον γράφο.
Υπολογίζει τα συντομότερα μονοπάτια από έναν κόμβο αφετηρίας και εκτυπώνει τα αποτελέσματα.
