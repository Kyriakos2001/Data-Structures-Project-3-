# Question5

GraphTypes.h
Edge: Αυτή η δομή αναπαριστά μια ακμή του γράφου και περιλαμβάνει τον προορισμό (endpoint) και έναν δείκτη (nextedge) που δείχνει στην επόμενη ακμή.
Graph: Αυτή η δομή αναπαριστά τον γράφο και περιλαμβάνει τον αριθμό των κορυφών (n) και τις λίστες γειτνίασης (firstedge).
Boolean: Τύπος δεδομένων για αληθοτιμές (TRUE/FALSE).
Vertex: Τύπος δεδομένων για τις κορυφές του γράφου.
Δηλώσεις Συναρτήσεων:

Initialize: Αρχικοποιεί τον γράφο με δοθέντα αριθμό κορυφών.
InsertEdge: Εισάγει μια ακμή στον γράφο.
ShowGraph: Εμφανίζει τον γράφο.
DepthFirst: Εκτελεί διάσχιση βάθους στον γράφο.
SimplePathCheck: Ελέγχει αν υπάρχει απλό μονοπάτι μεταξύ δύο κορυφών.
PrintElement: Εκτυπώνει ένα στοιχείο.

UndirectedGraph.c
Υλοποίηση των συναρτήσεων που δηλώθηκαν στο GraphTypes.h:

Initialize: Αρχικοποιεί τον γράφο και τις λίστες γειτνίασης.
InsertEdge: Προσθέτει μια ακμή στον γράφο, προσθέτοντας την ακμή και στις δύο κατευθύνσεις λόγω του μη κατευθυνόμενου χαρακτήρα του γράφου.
ShowGraph: Εμφανίζει τις κορυφές και τις γειτονικές τους κορυφές.
DepthFirst: Εκτελεί διάσχιση βάθους στον γράφο και εκτυπώνει τις κορυφές που επισκέπτεται.
SimplePathCheck: Ελέγχει αν υπάρχει απλό μονοπάτι μεταξύ δύο κορυφών, χρησιμοποιώντας βοηθητική συνάρτηση αναδρομής (SimplePathCheckUtil).

main.c
Η κύρια συνάρτηση που επιδεικνύει τη λειτουργικότητα των παραπάνω συναρτήσεων:

Διαβαζει τον γράφο από ένα αρχείο εισόδου.
Εμφανίζει τον αρχικό γράφο.
Εκτελεί διάσχιση βάθους και εκτυπώνει τις κορυφές.
Ζητά από τον χρήστη δύο κορυφές για έλεγχο απλού μονοπατιού και εμφανίζει το αποτέλεσμα.
