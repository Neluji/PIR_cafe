# Projet d'initiation à la recherche
## Conception d'une machine à café résiliente (et connectée)

---
## Précautions d’utilisations

Pour des raisons de sécurité évidentes, il est strictement défendu de toucher le circuit pompe / corps de chauffe lorsque la machine est allumée et branchée sur secteur.

---
## Installation


### Software :

Après avoir téléchargé les fichiers source, définir dans le programme main une instance de `Cafetiere` sans argument. Le constructeur se chargera d’initialiser les autres composants. Une fois cela fait, il suffit d’appeler dans la boucle principale la méthode `fonctionne()` de `Cafetiere`.

#### Paramètres :

Les paramètres peuvent être ajustés dans le fichier `Cafetiere.h` au moyen des `define` dédidés. On retrouve :
* Les paliers de température pour le corps de chauffe (`PALIER_TEMP_INF` et `PALIER_TEMP_SUP`)
* Les temps de fonctionnement de la pompe pour chaque café, basé sur un débit de ~20 cL/min (`TEMPS_CAFE_FILTRE` et `TEMPS_CAFE_EXPRESSO`)
* Le temps avant la mise en veille de la machine (`SLEEP_TIME`)


### Hardware :

Les périphériques requis sont 2 boutons, 1 écran OLED et 1 LED de technologie GROVE de préférence. Il est possible de remplacer la pompe et le corps de chauffe par 2 LEDs supplémentaires, dont une couplée avec 1 potentiomètre pour simuler le corps de chauffe.

#### Brochage :

Le brochage est défini dans le fichier `Cafetiere.h` au moyen des `define` dédidés. Par défaut, le brochage est le suivant :
* Led alim : `D3`
* Bouton sélection : `D6`
* Bouton validation : `D5`
* Corps de chauffe : `D7`
* Capteur de température : `A0`
* Pompe : `D8`
---
## Mode d’emploi


L’utilisateur commence par mettre la machine sous tension avec le bouton on/off après l’avoir branchée sur secteur. Il peut ensuite sélectionner le type de café (filtre ou expresso) désiré grâce à l’interface constituée de deux boutons et d’un écran. Un bouton permet de faire défiler les options et l’autre permet de valider le choix actuel. L’apport en eau et en café/filtre est à la charge de l’utilisateur.
Une fois le choix du café effectué, la préparation est lancée : l’écran permet de suivre en temps réel la progression de la préparation tandis que l’application embarquée contrôle la pompe et le corps de chauffe pour s’assurer de délivrer un café avec un volume et une température adéquats. A la fin du cycle, l’utilisateur est informé qu’il peut récupérer sa boisson.
La machine se met également en veille au bout de 30 minutes d’inactivité.
Pour des raisons de sécurité évidentes, il est strictement défendu de toucher le circuit pompe / corps de chauffe lorsque la machine est allumée et branchée sur secteur.
