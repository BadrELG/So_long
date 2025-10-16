# 🎮 So_long - École 42 Project

![42 Badge](https://img.shields.io/badge/École_42-so_long-blue?style=flat-square)
![C Language](https://img.shields.io/badge/language-C-blue?style=flat-square)
![MinilibX](https://img.shields.io/badge/graphics-MinilibX-green?style=flat-square)
![Progress](https://img.shields.io/badge/progress-Phase_2_Complete-brightgreen?style=flat-square)

## 📋 Table des Matières
- [🎯 Vue d'ensemble](#-vue-densemble)
- [📚 À propos de l'École 42](#-à-propos-de-lécole-42)
- [🚀 Statut du Projet](#-statut-du-projet)
- [🏗️ Architecture](#️-architecture)
- [⚙️ Installation](#️-installation)
- [🎮 Utilisation](#-utilisation)
- [📖 Règles du Jeu](#-règles-du-jeu)
- [🛠️ Technologies](#️-technologies)
- [📈 Roadmap](#-roadmap)

## 🎯 Vue d'ensemble

**So_long** est un projet de l'École 42 consistant à créer un jeu 2D en C utilisant la bibliothèque graphique MinilibX. Le joueur doit collecter tous les objets sur une carte et atteindre la sortie en évitant les obstacles.

### 🎮 Objectifs pédagogiques
- Manipulation de fenêtres graphiques
- Gestion d'événements (clavier, souris, fermeture)
- Parsing et validation de fichiers
- Gestion mémoire rigoureuse
- Respect de la norme 42

### 🔧 Contraintes spécifiques 42
- **Norme 42** : Règles strictes de codage (max 25 lignes/fonction, 5 fonctions/fichier, etc.)
- **Pas de bibliothèques externes** sauf celles autorisées
- **Gestion mémoire manuelle** : Aucune fuite tolérée
- **Makefile obligatoire** avec règles standard

## 🚀 Statut du Projet

### ✅ Phase 1 : Setup et Configuration (Terminée)
- [x] Installation et compilation de MinilibX
- [x] Structure du projet mise en place
- [x] Structures de données définies
- [x] Test MinilibX basique fonctionnel

### ✅ Phase 2 : Parsing et Validation (Terminée - 22/08/2025)
- [x] Lecture des fichiers `.ber`
- [x] Validation complète des cartes
- [x] Gestion d'erreurs robuste
- [x] Architecture modulaire conforme à la norme 42

**🎯 Modules implémentés :**
```
src/
├── parsing/
│   ├── map_parsing.c      # Lecture fichier et création tableau
│   ├── map_validation.c   # Validation caractères et forme
│   ├── map_borders.c      # Validation bordures murées
│   └── map_logic.c        # Validation éléments de jeu
└── error/
    └── error_handler.c    # Gestion d'erreurs centralisée
```

### 🔄 Phase 3 : Affichage Graphique (En cours)
- [ ] Chargement des sprites
- [ ] Affichage de la carte
- [ ] Gestion de la fenêtre

### ⏳ Phases suivantes
- **Phase 4** : Gestion des événements
- **Phase 5** : Logique du jeu
- **Phase 6** : Tests et finalisation

## 🏗️ Architecture

```
so_long/
├── Makefile
├── so_long.h              # Header principal
├── main.c                 # Point d'entrée
├── src/
│   ├── parsing/           # Modules de parsing
│   ├── error/             # Gestion d'erreurs
│   ├── game/              # Logique de jeu (à venir)
│   └── graphics/          # Rendu graphique (à venir)
├── libft/                 # Bibliothèque personnelle 42
├── mlx/                   # MinilibX
├── maps/                  # Cartes de test
└── sprites/               # Ressources graphiques
```

## ⚙️ Installation

### Prérequis
- **macOS** ou **Linux**
- **GCC** ou **Clang**
- **Make**
- **X11** (Linux) ou **AppKit** (macOS)

### Compilation
```bash
git clone https://github.com/BadrELG/So_long.git
cd So_long
make
```

## 🎮 Utilisation

```bash
./so_long maps/example.ber
```

### Format des cartes (.ber)
- `0` : Espace vide
- `1` : Mur
- `C` : Collectible
- `E` : Sortie
- `P` : Position du joueur

### Exemple de carte valide
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## 📖 Règles du Jeu

1. **Collecte** : Ramasser tous les collectibles (`C`)
2. **Sortie** : Atteindre la sortie (`E`) après avoir tout collecté
3. **Mouvement** : Utiliser `WASD` ou les flèches directionnelles
4. **Échapper** : Presser `ESC` pour quitter

### Contraintes de carte
- Doit être rectangulaire
- Entourée de murs (`1`)
- Contenir exactement 1 joueur (`P`) et 1 sortie (`E`)
- Au moins 1 collectible (`C`)

## 🛠️ Technologies

- **Langage** : C (norme 42)
- **Graphiques** : MinilibX
- **Gestion mémoire** : Garbage collector personnalisé
- **Lecture fichier** : get_next_line (projet 42)
- **Bibliothèque** : libft (bibliothèque personnelle 42)

## 📈 Roadmap

| Phase | Statut | Durée estimée | Description |
|-------|--------|---------------|-------------|
| **Phase 1** | ✅ | 1-2 jours | Setup et configuration |
| **Phase 2** | ✅ | 2-3 jours | Parsing et validation |
| **Phase 3** | 🔄 | 2-3 jours | Affichage graphique |
| **Phase 4** | ⏳ | 2 jours | Gestion des événements |
| **Phase 5** | ⏳ | 2 jours | Logique du jeu |
| **Phase 6** | ⏳ | 1-2 jours | Tests et finalisation |

**Durée totale estimée :** 10-15 jours

---

### 🎓 Contexte École 42

Ce projet fait partie du tronc commun de l'École 42, visant à développer les compétences en programmation graphique et en gestion d'événements. Il prépare aux projets plus avancés comme **cub3d** (raycasting 3D) et **miniRT** (raytracing).

### 📞 Contact

- **GitHub** : [BadrELG](https://github.com/BadrELG)
- **École 42** : Étudiant en cursus

---

*Projet réalisé dans le cadre du cursus de l'École 42* 🚀
