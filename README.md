# 🔄 Push_swap 

## 🎯 Objectifs

- Écrire un programme `push_swap` qui **reçoit des entiers non triés** en paramètres.  
- Le programme doit afficher **la liste d'instructions** permettant de **trier la pile `a`** dans l'ordre croissant.  
- Ces instructions seront ensuite vérifiées avec un programme `checker`.  

## 🧩 Les règles  

Le système est basé sur **2 piles** :  

- 📦 `a` : pile contenant les entiers à trier (au départ)
- 🧺 `b` : pile vide (utilisée comme zone temporaire)

**langage minimaliste** pour manipuler ces piles :  

| Instruction | Effet |
|-------------|-------|
| `sa` | Swap les deux premiers éléments de `a` |
| `sb` | Swap les deux premiers de `b` |
| `ss` | `sa` et `sb` en même temps |
| `pa` | Push de `b` vers `a` |
| `pb` | Push de `a` vers `b` |
| `ra` | Rotate `a` vers le haut |
| `rb` | Rotate `b` vers le haut |
| `rr` | `ra` et `rb` en même temps |
| `rra` | Rotate `a` vers le bas |
| `rrb` | Rotate `b` vers le bas |
| `rrr` | `rra` et `rrb` en même temps |

**Le but** : utiliser ces instructions pour **trier `a`** (le plus petit en haut), avec **le moins d'opérations possibles**.


### 🏗️ Stratégies implémentée : Radix sort

---

🧠 **Ce que j’ai appris**  

•	🔁 Implémenter différents algorithmes de tri (par ex. insertion, radix, quicksort simplifié)  
•	🧮 Comprendre la complexité algorithmique (O(n), O(n²), etc.)  
• 💡 Optimiser le nombre d’instructions émises  
•	📊 Analyser et adapter dynamiquement la stratégie selon la taille de la pile  

--- 

✅ **STATUT:**  
📅 Date de rendu : 01.04.2025    
📝 Note obtenue : 84/100

---
