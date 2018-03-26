#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Common.h"
#include "Language.h"

class recupcommand : public CommandScript
{
	public: recupcommand() : CommandScript("recupcommand") {}

	ChatCommand* GetCommands() const
	{
		static ChatCommand vipCommandTable[] =

		{
			{ NULL, 0, false, NULL, "", NULL }
		};
		static ChatCommand commandTable[] =
		{
			{ "recup", SEC_PLAYER, true, &HandleRecupCommand, "", NULL},
			{ NULL, 0, false, NULL, "", NULL }
		};
		
		return commandTable;
	}



static bool HandleRecupCommand(ChatHandler* handler, const char* args)
{

	Player* player = handler->GetSession()->GetPlayer();
	QueryResult recup = CharacterDatabase.PQuery("SELECT `recup` FROM characters WHERE guid ='%u'", player->GetGUID());

	Field* fields = recup->Fetch();
	uint32 RecupOuPas = fields[0].GetUInt32();
	if(RecupOuPas == 1)
	{
		QueryResult recupSkillItem = LoginDatabase.PQuery("SELECT id,id_a_envoyer,nombre_a_envoyer,command FROM recup WHERE fait='0' and id_char = '%u'", player->GetGUID());
		if(recupSkillItem)
		{
			uint32 count = 0;
			count = recupSkillItem->GetRowCount();
			Field* fields = recupSkillItem->Fetch();
			for(unsigned int i = 0; i < count; i++)
			{
				uint32 id = fields[0].GetUInt32();
				uint32 id_a_envoyer = fields[1].GetUInt32();
				uint32 nombre_a_envoyer = fields[2].GetUInt32();
				std::string command = fields[3].GetString();
		
				if (command == "AddItem") 
				{
					player->AddItem(id_a_envoyer,nombre_a_envoyer);
					LoginDatabase.PExecute("delete from recup WHERE id ='%u'", id );
				}
				if (command == "GiveLevel")
				{
					player->SetLevel(nombre_a_envoyer);
					LoginDatabase.PExecute("delete from recup WHERE id ='%u'", id );
				}

				if (command == "ModifyMoney")
				{
					player->ModifyMoney(nombre_a_envoyer);
					LoginDatabase.PExecute("delete from recup WHERE id ='%u'", id );
				}

				if (command == "Learn")
				{
					player->learnSpell(id_a_envoyer, false);
					LoginDatabase.PExecute("delete from recup WHERE id ='%u'", id );
				}

				if (command == "UpdateSkill")
				{
					player->UpdateSkill(id_a_envoyer, nombre_a_envoyer);
					LoginDatabase.PExecute("delete from recup WHERE id ='%u'", id );
				}

				recupSkillItem->NextRow();
			}	
		}

		CharacterDatabase.PExecute("UPDATE characters SET recup='2' WHERE guid ='%u'", player->GetGUID());
		handler->SendSysMessage("Votre récupération a été effectuée. Bon jeu sur DeathWing");

	}
	else if (RecupOuPas == 2)	
	{
		handler->SendSysMessage("Votre récupération est déjà terminée.");
		handler->SetSentErrorMessage(true);
	}
	else
	{
		handler->SendSysMessage("Vous n'avez pas de récupération en attente.");
		handler->SetSentErrorMessage(true);
	}


	return true;

}

};

void AddSC_recupcommand()
{
new recupcommand();
}