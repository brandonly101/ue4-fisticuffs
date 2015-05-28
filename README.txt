CS 188 VR - Fisticuffs

Brandon Ly
UID: 304-136-729
Email: brandonly101@ucla.edu

Kevin Luc
UID: 004-180-969
Email: luckk@ucla.edu

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

Game Name: Fisticuffs!

Game Concept: You control a brawler/drunkard in a medieval-like
     setting who is going around seeking the best booze in the
     kingdom. However, the bars/inns only let the strong in so you must prove
     yourself by defeating other brawlers to win your prize.
 
Game Mechanics:
     - Upon entering their "aggro" range opponents will swarm the player and
     attempt to engage him/her
     - Combat is confined to an "arena" with specified boundaries
     - Combat is fist fighting only and involves only throwing punches
     and blocking
     - In order to defeat enemies, the player must deliver a knock-out punch
     - The player is defeated if he/she receives a knock-out punch from an
     enemy
     - All fighter maintains a discombobulation meter which tracks
     the amount of damage they have taken. The higher the meter, the
     more vulnerable they are to a knock-out punch.
     - All fighters maintain a stamina resource
       -Stamina is expended for every punch the fighter throws
       -Stamina is recovered while the fighter is idle
       -Stamina does not recover while the fighter is blocking
       -Stamina is also lost if the fighter gets punched while blocking

Entities:           
      -Player
      -Enemy brawlers
      
Binary Decision Tree:
      - Is player within aggro range?
      Yes:
	-Is player in line of sight?
	    Yes: Pursue player
	    No: Idle
      No: Idle

What Does "Pursue" Mean?
     When a enemy pursues a player, they simply run towards him. Once the
     enemy overlaps with the player's collision sphere, they stop and
     attempt to engage the player.

Implementation:
     We have all enemies have a target variable, which is set to the
     player when he/she comes into their aggro range and unset if the
     player is able to escape the enemies' aggro range. Punches are
     implemented by attaching sphere colliders to the player's hands
     which can then act as triggers. 

Future Development:
     We plan to make the combat AI much more intelligent and increase
     the range of punches that can be thrown, from light to heavy. We
     also plan to tie in the stamina resource to the discombobulation
     meter, such that each character's max stamina is reduced based on
     discombobulation. We also plan to add in slow motion to the
     knockout punches for added effect. A story will be added with time.
