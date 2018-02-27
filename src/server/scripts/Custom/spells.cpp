
class spells : public CreatureScript
{
	public: spells() : CreatureScript("spells") { }

	//MENU GENERAL
	bool OnGossipHello(Player* pPlayer, Creature* pCreature) // Affichage du menu
	{
		pPlayer->ADD_GOSSIP_ITEM(4, "Zone Shop", GOSSIP_SENDER_MAIN, 1); // Première option
		pPlayer->ADD_GOSSIP_ITEM(4, "Zone Duel", GOSSIP_SENDER_MAIN, 2); // Deuxième option
		pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Quitter", GOSSIP_SENDER_MAIN, 3); // Troisième option ( Fermeture du menu )
		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction) // Action lors du clique de l'option choisi
	{
		switch(uiAction)
		{
		case 1: // Téléportation Zone Shop
		{
			pPlayer->CLOSE_GOSSIP_MENU(); // Fermeture du menu
			pPlayer->TeleportTo(1, 3300.689697, -4487.513672, 268.167877, 4.683797); // (id de la Map, coordonnées X, coordonnées Y, coordonnées Z, Orientation)
			break;
		}
		case 2: // Téléportation Zone Duel
		{
			pPlayer->CLOSE_GOSSIP_MENU(); // Fermeture du menu
			pPlayer->TeleportTo(1, -8811.073242, 335.773315, 346.419830, 5.517128); // (id de la Map, coordonnées X, coordonnées Y, coordonnées Z, Orientation)
			break;
		}
		case 3: // Quitter
		{ 
			pCreature->MonsterWhisper("Au revoir.", pPlayer->GetGUID()); // Message "Au revoir" entre le pnj et le joueur
			pPlayer->CLOSE_GOSSIP_MENU(); // Fermeture du menu
			break;
		}
		}
	return true; 
	}
};

void AddSC_spells()
{
new spells(); // Nom du script à donné au pnj dans la base de données
}