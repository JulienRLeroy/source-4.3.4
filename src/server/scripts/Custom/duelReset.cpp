#include "Player.h"
#include "ScriptMgr.h"


class player_resetduel_script : public PlayerScript
{
public:
    player_resetduel_script() : PlayerScript("player_resetduel_script"){}
 
    void OnDuelRequest(Player* player1, Player* player2)
    {
        //Reset des cd
        player1->RemoveArenaSpellCooldowns();
        player2->RemoveArenaSpellCooldowns();
		
 
        //Rend mana et vie au joueur 1
        player1->SetHealth(player1->GetMaxHealth());
        if (player1->getPowerType() == POWER_MANA)
            player1->SetPower(POWER_MANA, player1->GetMaxPower(POWER_MANA));
 
        //Rend mana et vie au joueur 2
        player2->SetHealth(player2->GetMaxHealth());
        if (player2->getPowerType() == POWER_MANA)
            player2->SetPower(POWER_MANA, player2->GetMaxPower(POWER_MANA));
    }
	
	  // void OnDuelStart (Player* player1, Player* player2)
    // {

		// ChatHandler(player1->GetSession()).PSendSysMessage("Préparez-vous à un combat épique, vous êtes classé !"); //envoi un message au joueur 1
		// ChatHandler(player2->GetSession()).PSendSysMessage("Préparez-vous à un combat épique, vous êtes classé !"); //envoi un message au joueur 1
		
	// }
	
    
    void OnDuelEnd(Player* winner, Player* loser, DuelCompleteType) // Quand le duel se termine, les joueurs récupèrent leur vie et leur cd
    {
		
		
        winner->RemoveArenaSpellCooldowns(); 
        loser->RemoveArenaSpellCooldowns();
		winner->AttackStop(); 
        winner->CastStop();
		loser->AttackStop();
        loser->CastStop(); 
 
        winner->SetHealth(winner->GetMaxHealth());
        if (winner->getPowerType() == POWER_MANA) 
            winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
         
        loser->SetHealth(loser->GetMaxHealth()); 
        if (loser->getPowerType() == POWER_MANA)
            loser->SetPower(POWER_MANA, loser->GetMaxPower(POWER_MANA));
			
		// QueryResult exist = LoginDatabase.PQuery("SELECT * FROM site_module_classement WHERE guid ='%u'", winner->GetGUID().GetCounter());
		// if(exist)
		// {
			// LoginDatabase.PExecute("UPDATE site_module_classement SET win=win+1 WHERE guid ='%u'", winner->GetGUID().GetCounter());
		// }
		// else
		// {
			// LoginDatabase.PExecute("INSERT INTO site_module_classement SET win=1, guid ='%u', name = '%s'", winner->GetGUID().GetCounter(), winner->GetName());
		// }
   
		// QueryResult existt = LoginDatabase.PQuery("SELECT * FROM site_module_classement WHERE guid ='%u'", loser->GetGUID().GetCounter());
		// if(existt)
		// {
			// LoginDatabase.PExecute("UPDATE site_module_classement SET lose=lose+1 WHERE guid ='%u'", loser->GetGUID().GetCounter());
		// }
		// else
		// {
			// LoginDatabase.PExecute("INSERT INTO site_module_classement SET lose=1, guid ='%u', name = '%s'", loser->GetGUID().GetCounter(), loser->GetName());
		// }
	
	}
};
            
void AddSC_player_resetduel_script()
{
    new player_resetduel_script();
}