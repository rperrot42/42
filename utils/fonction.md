- perror = afficher une erreur;
- strerror(errno) renvoie une chaîne de caractères décrivant l'erreur actuelle qui s'est 
produite lors de l'ouverture du fichier. Cela peut être utile pour afficher des messages 
d'erreur significatifs et informatifs lors de la manipulation des erreurs dans les programmes
en C.
- access est utilisée pour vérifier l'existence du fichier "mon_fichier.txt" et si 
l'utilisateur a la permission de le lire (R_OK). La macro F_OK est utilisée pour 
vérifier l'existence du fichier, tandis que R_OK est utilisée pour vérifier 
la permission de lecture. D'autres macros comme W_OK (écriture) et X_OK (exécution)
- dup permet de duppliquer un fd soit un transcrpiteur de fichier
La fonction dup2 en C est similaire à la fonction dup, mais elle permet de contrôler 
explicitement le numéro de descripteur de fichier de la copie. Contrairement à dup, 
qui choisit automatiquement le plus petit descripteur de fichier disponible pour 
la copie, dup2 vous permet de spécifier le numéro de descripteur de fichier que 
vous souhaitez utiliser pour la copie.
- execve permet d'executer des commandes
