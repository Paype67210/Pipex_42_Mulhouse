<picture>
<img alt="Entête du dépôt Pipex_42_Mulhouse." src="https://github.com/Paype67210/Pipex_42_Mulhouse/blob/main/Tools/cover-pipex.png">
</picture>

### Objectifs du projet

- **Recréer le comportement des pipes Unix** : Permettre de rediriger l'entrée d'un fichier vers un programme, puis de chaîner sa sortie dans un autre programme, et enfin rediriger cette sortie vers un fichier.
- **Exécution de commandes shell** : Le programme doit être capable d'exécuter des commandes comme `ls`, `grep`, ou `wc` et de les chaîner à travers des pipes.
- **Gestion des processus enfants** : Le projet implique la création de processus enfants via des appels système comme `fork()`, et la redirection des flux d'entrée et de sortie avec `dup2()`.

### Compétences acquises

- **Programmation système et gestion des processus** : Utilisation d'appels système comme `pipe()`, `fork()`, `execve()` et `wait()` pour créer des pipes entre les processus et exécuter des commandes externes.
- **Redirection des entrées et sorties** : Apprentissage de la gestion fine des descripteurs de fichiers avec `dup2()` pour rediriger l'entrée et la sortie standard des processus.
- **Gestion des erreurs et des signaux** : Implémentation de vérifications robustes pour les erreurs liées aux appels système et gestion des signaux pour contrôler la terminaison des processus enfants.

### Détails techniques

- **Gestion des descripteurs de fichiers** : Redirection de l'entrée et de la sortie via `dup2()` pour lire à partir du fichier d'entrée et écrire dans le fichier de sortie.
- **Exécution des commandes avec `execve()`** : Remplacement du processus courant par l'exécution de commandes shell tout en prenant en compte les chemins d'accès définis dans la variable d'environnement PATH.
- **Chaînage des pipes** : Utilisation de `pipe()` pour relier la sortie standard de la première commande à l'entrée standard de la seconde.

### Bonus : Gestion des commandes multiples

Dans le cadre du bonus, il est possible d'étendre le programme pour prendre en charge un nombre illimité de commandes chaînées via des pipes :
```bash
< infile cmd1 | cmd2 | cmd3 | ... | cmdN > outfile
```
Cela implique de gérer plusieurs processus simultanément et de chaîner les pipes correctement pour transférer les données d'une commande à l'autre, tout en optimisant l'usage des descripteurs de fichiers.

### Conclusion

Le projet **Pipex** est une introduction essentielle à la programmation système en C. Il permet d'acquérir une bonne maîtrise des appels système, de la gestion des processus et de la redirection de flux. C'est un projet fondamental pour comprendre comment les commandes Unix fonctionnent en arrière-plan, et comment les processus communiquent entre eux via des pipes.

### Ressources supplémentaires

    [Guide sur la programmation avec pipes et processus](https://www.codequoi.com/pipe-une-methode-de-communication-inter-processus/)
    [Documentation sur la gestion des processus en C](https://studylibfr.com/doc/1854682/la-gestion-des-processus---syst%C3%A8me-d-exploitation-et-lang...)
    [Tutoriel sur les appels système Unix](https://fr.linux-console.net/?p=29788)