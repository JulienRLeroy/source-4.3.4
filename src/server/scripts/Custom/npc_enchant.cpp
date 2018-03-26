#include "ScriptPCH.h"
 
enum Enchants
{
    ENCHANT_WEP_LANDSLIDE                   = 4099,
    ENCHANT_WEP_POWER_TORRENT               = 4097,
    ENCHANT_WEP_WINDWALK                    = 4098,
    ENCHANT_WEP_HEARTSONG                   = 4084,
    ENCHANT_WEP_HURRICANE                   = 4083,
    ENCHANT_WEP_ELEMENTAL_SLAYER            = 4074,
    ENCHANT_WEP_AVALANCHE                   = 4067,
    ENCHANT_WEP_MENDING                     = 4066,
    ENCHANT_2HWEP_MIGHTY_AGILITY            = 4227,
 
    ENCHANT_OFF_HAND_SUPERIOR_INTELLECT     = 4091,
    ENCHANT_SHIELD_MASTERY                  = 4085,
    ENCHANT_SHIELD_PROTECTION               = 4073,
 
    ENCHANT_HEAD_VICIOUS_INTELLECT          = 4245,
    ENCHANT_HEAD_VICIOUS_AGILITY            = 4246,
    ENCHANT_HEAD_VICIOUS_STRENGTH           = 4247,
 
    ENCHANT_SHOULDER_VICIOUS_INTELLECT      = 4248,
    ENCHANT_SHOULDER_VICIOUS_AGILITY        = 4250,
    ENCHANT_SHOULDER_VICIOUS_STRENGTH       = 4249,
 
    ENCHANT_CLOAK_GREATER_CRITICAL_STRIKE   = 4100,
    ENCHANT_CLOAK_GREATER_INTELLECT         = 4096,
    ENCHANT_CLOAK_PROTECTION                = 4090,
    ENCHANT_CLOAK_GREATER_SPELL_PIERCING    = 4064,
    ENCHANT_CLOACK_AGILITY                  = 1099,
 
    ENCHANT_GLOVES_GREATER_MASTERY          = 4107,
    ENCHANT_GLOVES_MIGHTY_STRENGTH          = 4106,
    ENCHANT_GLOVES_GREATER_EXPERTISE        = 4082,
    ENCHANT_GLOVES_HASTE                    = 4068,
    ENCHANT_GLOVES_AGILITY                  = 3222,
 
    ENCHANT_BRACERS_GREATER_CRITICAL_STRIKE = 4101,
    ENCHANT_BRACERS_GREATER_SPEED           = 4108,
    ENCHANT_BRACERS_AGILITY                 = 4258,
    ENCHANT_BRACERS_MAJOR_STRENGTH          = 4256,
    ENCHANT_BRACERS_MIGHTY_INTELLECT        = 4257,
    ENCHANT_BRACERS_GREATER_EXPERTISE       = 4095,
    ENCHANT_BRACERS_EXCEPTIONAL_SPIRIT      = 4093,
    ENCHANT_BRACERS_PRECISION               = 4089,
    ENCHANT_BRACERS_SUPERIOR_DODGE          = 4086,
 
    ENCHANT_CHEST_PEERLESS_STATS            = 4102,
    ENCHANT_CHEST_GREATER_STAMINA           = 4103,
    ENCHANT_CHEST_EXCEPTIONAL_SPIRIT        = 4088,
    ENCHANT_CHEST_MIGHTY_RESILIENCE         = 4077,
 
    ENCHANT_BOOTS_ASSASSINS_STEP            = 4105,
    ENCHANT_BOOTS_LAVAWALKER                = 4104,
    ENCHANT_BOOTS_MASTERY                   = 4094,
    ENCHANT_BOOTS_PRECISION                 = 4092,
    ENCHANT_BOOTS_MAJOR_AGILITY             = 4076,
    ENCHANT_BOOTS_HASTE                     = 4069,
 
    ENCHANT_RING_AGILITY                    = 4079,
    ENCHANT_RING_GREATER_STAMINA            = 4081,
    ENCHANT_RING_INTELLECT                  = 4080,
    ENCHANT_RING_STRENGTH                   = 4078,
 
    ENCHANT_LEGS_DRAGONSCALE                = 4126,
    ENCHANT_LEGS_CHARSCALE                  = 4127,
    ENCHANT_LEGS_DRAKEHIDE                  = 4270,
    ENCHAANT_POWERFUL_GHOSTLY_THREAD        = 4110,
    ENCHAANT_POWERFUL_ENCHANTED_THREAD      = 4112,
    ENCHANT_LEGS_LEG                        = 71720,
 
    ENCHANT_WAIST_BUCKLE                    = 3729,
 
    /*Runeforge*/
    RUNEFORGE_CINDERGLAICER                 = 3369,
    RUNEFORGE_LICHBANE                      = 3366,
    RUNEFORGE_RAZORICE                      = 3370,
    RUNEFORGE_SPELLBREAKING                 = 3595,
    RUNEFORGE_SPELLSHATTERING               = 3367,
    RUNEFORGE_SWORDBREAKING                 = 3594,
    RUNEFROGE_SWORDSHATTERING               = 3365,
    RUNEFORGE_FALLEN_CRUSADE                = 3368,
    RUNEFORGE_NERUBIAN_CARAPACE             = 3883,
    RUNEFORGE_STONESKIN_GARGYOLE            = 3847
 
 
};
 
#define ONE_HAND_WEAPON_COST    0
#define TWO_HAND_WEAPON_COST    0
#define MAIN_PIECES_COST        0
#define OFF_PIECES_COST         0
#define SHIELD_COST             0
 
void Enchant(Player* player, Item* item, uint32 enchantid)
{
    if (!item)
    {
        player->GetSession()->SendNotification(player->GetSession()->GetTrinityString(30000), LANG_UNIVERSAL, player, false);
        return;
    }
 
    if (!enchantid)
        return;
       
    player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, false);
    item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
    player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, true);
    std::string color = "|cff";
    switch (item->GetTemplate()->Quality)
    {
    case 0:
        color += "9d9d9d";
        break;
    case 1:
        color += "ffffff";
        break;
    case 2:
        color += "1eff00";
        break;
    case 3:
        color += "0070dd";
        break;
    case 4:
        color += "a335ee";
        break;
    case 5:
        color += "ff8000";
        break;
    }
    std::string itemname = item->GetTemplate()->Name1;
    ChatHandler(player->GetSession()).PSendSysMessage(player->GetSession()->GetTrinityString(30001), LANG_UNIVERSAL, player,true, color.c_str(), itemname.c_str());
}
 
void PrismaticEnchant(Player* player, Item* item, uint32 enchantid)
{
    if (!item)
    {
        player->GetSession()->SendNotification(player->GetSession()->GetTrinityString(30000), LANG_UNIVERSAL, player, false);
        return;
    }
 
    if (!enchantid)
        return;
 
    player->ApplyEnchantment(item, PRISMATIC_ENCHANTMENT_SLOT, false);
    item->SetEnchantment(PRISMATIC_ENCHANTMENT_SLOT, enchantid, 0, 0);
    player->ApplyEnchantment(item, PRISMATIC_ENCHANTMENT_SLOT, true);
    std::string color = "|cff";
    switch (item->GetTemplate()->Quality)
    {
    case 0:
        color += "9d9d9d";
        break;
    case 1:
        color += "ffffff";
        break;
    case 2:
        color += "1eff00";
        break;
    case 3:
        color += "0070dd";
        break;
    case 4:
        color += "a335ee";
        break;
    case 5:
        color += "ff8000";
        break;
    }
    std::string itemname = item->GetTemplate()->Name1;
    ChatHandler(player->GetSession()).PSendSysMessage(player->GetSession()->GetTrinityString(30001), LANG_UNIVERSAL, player, true, color.c_str(), itemname.c_str());
}
 
class npc_enchantment : public CreatureScript
{
    std::string iconSize = "15";
public:
    npc_enchantment() : CreatureScript("npc_enchantment") { }
 
        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (player->getClass() == CLASS_DEATH_KNIGHT)
            {
                player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\Spell_deathknight_frozenruneweapon:" + iconSize + " |t|r [Runeforge]", GOSSIP_SENDER_MAIN, 0);
            }
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Weapon]", GOSSIP_SENDER_MAIN, 1);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant 2H Weapon]", GOSSIP_SENDER_MAIN, 2);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Off-Hand]", GOSSIP_SENDER_MAIN, 3);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Head]", GOSSIP_SENDER_MAIN, 4);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Shoulders]", GOSSIP_SENDER_MAIN, 5);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Cloak]", GOSSIP_SENDER_MAIN, 6);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Chest]", GOSSIP_SENDER_MAIN, 7);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Bracers]", GOSSIP_SENDER_MAIN, 8);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Gloves]", GOSSIP_SENDER_MAIN, 9);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Waist]", GOSSIP_SENDER_MAIN, 13);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Legs]", GOSSIP_SENDER_MAIN, 10);
            player->ADD_GOSSIP_ITEM(1, "|TInterface\\icons\\trade_engraving:" + iconSize + " |t|r [Enchant Feet]", GOSSIP_SENDER_MAIN, 11);
 
            if (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) == 450)
                player->ADD_GOSSIP_ITEM(1, "[Enchant Rings]", GOSSIP_SENDER_MAIN, 12);
 
            player->SEND_GOSSIP_MENU(100001, creature->GetGUID());
            return true;
        }
 
        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            Item * mainItem;
 
            switch (action)
            {
                case 0: //Runefroge
                    player->ADD_GOSSIP_ITEM(1, "Main Hand", GOSSIP_SENDER_MAIN, 160);
                    player->ADD_GOSSIP_ITEM(1, "Off Hand", GOSSIP_SENDER_MAIN, 161);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100015, creature->GetGUID());
                    return true;
                    break;
                case 1: // Enchant Weapon
                    player->ADD_GOSSIP_ITEM(1, "Heartsong", GOSSIP_SENDER_MAIN, 102);
                    player->ADD_GOSSIP_ITEM(1, "Hurricane", GOSSIP_SENDER_MAIN, 103);
                    player->ADD_GOSSIP_ITEM(1, "Avalanche", GOSSIP_SENDER_MAIN, 100);
                    player->ADD_GOSSIP_ITEM(1, "Elemental Slayer", GOSSIP_SENDER_MAIN, 101);
                    player->ADD_GOSSIP_ITEM(1, "Landslide", GOSSIP_SENDER_MAIN, 104);
                    player->ADD_GOSSIP_ITEM(1, "Mending", GOSSIP_SENDER_MAIN, 105);
                    player->ADD_GOSSIP_ITEM(1, "Power Torrent", GOSSIP_SENDER_MAIN, 106);
                    player->ADD_GOSSIP_ITEM(1, "Windwalk", GOSSIP_SENDER_MAIN, 107);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100002, creature->GetGUID());
                    return true;
                    break;
 
                case 2: // Enchant 2H Weapon
                    {
                        mainItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                        if (!mainItem || mainItem->GetTemplate()->InventoryType != INVTYPE_2HWEAPON)
                        {
                            player->GetSession()->SendAreaTriggerMessage("|cffFF0000You need a Two-Hand Weapon equipped!");
                            return false;
                            player->CLOSE_GOSSIP_MENU();;
                        }
                        if (mainItem->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
                        {
                            player->ADD_GOSSIP_ITEM(1, "Heartsong", GOSSIP_SENDER_MAIN, 102);
                            player->ADD_GOSSIP_ITEM(1, "Hurricane", GOSSIP_SENDER_MAIN, 103);
                            player->ADD_GOSSIP_ITEM(1, "Avalanche", GOSSIP_SENDER_MAIN, 100);
                            player->ADD_GOSSIP_ITEM(1, "Elemental Slayer", GOSSIP_SENDER_MAIN, 101);
                            player->ADD_GOSSIP_ITEM(1, "Landslide", GOSSIP_SENDER_MAIN, 104);
                            player->ADD_GOSSIP_ITEM(1, "Mending", GOSSIP_SENDER_MAIN, 105);
                            player->ADD_GOSSIP_ITEM(1, "Power Torrent", GOSSIP_SENDER_MAIN, 106);
                            player->ADD_GOSSIP_ITEM(1, "Windwalk", GOSSIP_SENDER_MAIN, 107);
                            player->ADD_GOSSIP_ITEM(1, "Mighty Agility", GOSSIP_SENDER_MAIN, 108);
                            player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                            player->PlayerTalkClass->SendGossipMenu(100003, creature->GetGUID());
                            return true;
                        }
                    }
                    break;
 
                case 3: // Enchant Shield
                    {
                        mainItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                        if (!mainItem)
                        {
                            player->GetSession()->SendAreaTriggerMessage("|cffFF0000You need an Off-Hand or Shield equipped!");
                            player->CLOSE_GOSSIP_MENU();
                            return false;                          
                        }
                        if (mainItem->GetTemplate()->InventoryType == INVTYPE_SHIELD)
                        {
                            player->ADD_GOSSIP_ITEM(1, "Mastery", GOSSIP_SENDER_MAIN, 109);
                            player->ADD_GOSSIP_ITEM(1, "Protection", GOSSIP_SENDER_MAIN, 110);
                            player->ADD_GOSSIP_ITEM(1, "Superior Intellect", GOSSIP_SENDER_MAIN, 111);
                            player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                            player->PlayerTalkClass->SendGossipMenu(100004, creature->GetGUID());
                            return true;
                        }
                        if (mainItem->GetTemplate()->InventoryType == INVTYPE_WEAPONOFFHAND)
                        {
                            player->ADD_GOSSIP_ITEM(1, "Superior Intellect", GOSSIP_SENDER_MAIN, 111);
                            player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                            player->SEND_GOSSIP_MENU(100004, creature->GetGUID());
                        }
                       
                    }
                    break;
 
                case 4: // Enchant Head
                    player->ADD_GOSSIP_ITEM(1, "Arcanum of Vicious Agility - 60 Agility & 35 Resilience", GOSSIP_SENDER_MAIN, 112);
                    player->ADD_GOSSIP_ITEM(1, "Arcanum of Vicious Intellect - 60 Intellect & 35 Resilience", GOSSIP_SENDER_MAIN, 113);
                    player->ADD_GOSSIP_ITEM(1, "Arcanum of Vicious Strength - 60 Strength & 35 Resilience", GOSSIP_SENDER_MAIN, 114);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100005, creature->GetGUID());
                    return true;
                    break;
 
                case 5: // Enchant Shoulders
                    player->ADD_GOSSIP_ITEM(1, "Greater Inscription of the Vicious Agility - 50 Agility & 25 Resilience", GOSSIP_SENDER_MAIN, 115);
                    player->ADD_GOSSIP_ITEM(1, "Greater Inscription of the Vicious Intellect - 50 Intellect & 25 Resilience", GOSSIP_SENDER_MAIN, 116);
                    player->ADD_GOSSIP_ITEM(1, "Greater Inscription of the Vicious Strength - 50 Strength & 25 Resilience", GOSSIP_SENDER_MAIN, 117);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100006, creature->GetGUID());
                    return true;
                    break;
 
                case 6: // Enchant Cloak
                    player->ADD_GOSSIP_ITEM(1, "Greater Critical Strike", GOSSIP_SENDER_MAIN, 118);
                    player->ADD_GOSSIP_ITEM(1, "Greater Intellect", GOSSIP_SENDER_MAIN, 119);
                    player->ADD_GOSSIP_ITEM(1, "Greater Spell Piercing", GOSSIP_SENDER_MAIN, 120);
                    player->ADD_GOSSIP_ITEM(1, "Major Agility", GOSSIP_SENDER_MAIN, 156);
                    player->ADD_GOSSIP_ITEM(1, "Protection", GOSSIP_SENDER_MAIN, 121);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100007, creature->GetGUID());
                    return true;
                    break;
 
                case 7: //Enchant chest
                    player->ADD_GOSSIP_ITEM(1, "Exceptional Spirit", GOSSIP_SENDER_MAIN, 122);
                    player->ADD_GOSSIP_ITEM(1, "Greater Stamina", GOSSIP_SENDER_MAIN, 123);
                    player->ADD_GOSSIP_ITEM(1, "Mighty Resilience", GOSSIP_SENDER_MAIN, 124);
                    player->ADD_GOSSIP_ITEM(1, "Peerless Stats", GOSSIP_SENDER_MAIN, 125);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100008, creature->GetGUID());
                    return true;
                    break;
 
                case 8: //Enchant Bracers
                    player->ADD_GOSSIP_ITEM(1, "Agility", GOSSIP_SENDER_MAIN, 126);
                    player->ADD_GOSSIP_ITEM(1, "Exceptional Spirit", GOSSIP_SENDER_MAIN, 127);
                    player->ADD_GOSSIP_ITEM(1, "Greater Critical Strike", GOSSIP_SENDER_MAIN, 128);
                    player->ADD_GOSSIP_ITEM(1, "Greater Expertise", GOSSIP_SENDER_MAIN, 129);
                    player->ADD_GOSSIP_ITEM(1, "Greater Speed", GOSSIP_SENDER_MAIN, 130);
                    player->ADD_GOSSIP_ITEM(1, "Major Strength", GOSSIP_SENDER_MAIN, 131);
                    player->ADD_GOSSIP_ITEM(1, "Mighty Intellect", GOSSIP_SENDER_MAIN, 132);
                    player->ADD_GOSSIP_ITEM(1, "Precision", GOSSIP_SENDER_MAIN, 133);
                    player->ADD_GOSSIP_ITEM(1, "Superior Dodge", GOSSIP_SENDER_MAIN, 134);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100009, creature->GetGUID());
                    return true;
                    break;
 
                case 9: //Enchant Gloves
                    if (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) == 525)
                    {
                        player->ADD_GOSSIP_ITEM(1, "Blade Ward", GOSSIP_SENDER_MAIN, 102);
                        player->ADD_GOSSIP_ITEM(1, "Blood Draining", GOSSIP_SENDER_MAIN, 103);
                    }
                    player->ADD_GOSSIP_ITEM(1, "Greater Expertise", GOSSIP_SENDER_MAIN, 135);
                    player->ADD_GOSSIP_ITEM(1, "Greater Mastery", GOSSIP_SENDER_MAIN, 136);
                    player->ADD_GOSSIP_ITEM(1, "Haste", GOSSIP_SENDER_MAIN, 137);
                    player->ADD_GOSSIP_ITEM(1, "Mighty Strength", GOSSIP_SENDER_MAIN, 138);
                    player->ADD_GOSSIP_ITEM(1, "Major Agility", GOSSIP_SENDER_MAIN, 157);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100010, creature->GetGUID());
                    return true;
                    break;
 
                case 10: // Enchant Legs
                    player->ADD_GOSSIP_ITEM(1, "Dragonscale Leg Armor - 145 Stamina & 55 Agility", GOSSIP_SENDER_MAIN, 151);
                    player->ADD_GOSSIP_ITEM(1, "Charscale Leg Armor - 190 Attack Power & 55 Critical Strike", GOSSIP_SENDER_MAIN, 152);
                    player->ADD_GOSSIP_ITEM(1, "Drakehide Leg Armor - 95 Intellect & 80 Stamina", GOSSIP_SENDER_MAIN, 153);
                    player->ADD_GOSSIP_ITEM(1, "Powerful Ghostly Spellthread - 95 Intellect & 55 Spirit", GOSSIP_SENDER_MAIN, 154);
                    player->ADD_GOSSIP_ITEM(1, "Powerful Enchanted Spellthread - 145 Stamina", GOSSIP_SENDER_MAIN, 155);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100011, creature->GetGUID());
                    return true;
                    break;
 
                case 11: //Enchant feet
                    player->ADD_GOSSIP_ITEM(1, "Assassins Step", GOSSIP_SENDER_MAIN, 139);
                    player->ADD_GOSSIP_ITEM(1, "Haste", GOSSIP_SENDER_MAIN, 140);
                    player->ADD_GOSSIP_ITEM(1, "Lavawalker", GOSSIP_SENDER_MAIN, 141);
                    player->ADD_GOSSIP_ITEM(1, "Major Agility", GOSSIP_SENDER_MAIN, 142);
                    player->ADD_GOSSIP_ITEM(1, "Mastery", GOSSIP_SENDER_MAIN, 143);
                    player->ADD_GOSSIP_ITEM(1, "Precision", GOSSIP_SENDER_MAIN, 144);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100012, creature->GetGUID());
                    return true;
                    break;
 
                case 12: //Enchant rings
                    player->ADD_GOSSIP_ITEM(1, "Agility", GOSSIP_SENDER_MAIN, 145);
                    player->ADD_GOSSIP_ITEM(1, "Greater Stamina", GOSSIP_SENDER_MAIN, 146);
                    player->ADD_GOSSIP_ITEM(1, "Intellect", GOSSIP_SENDER_MAIN, 147);
                    player->ADD_GOSSIP_ITEM(1, "Strength", GOSSIP_SENDER_MAIN, 148);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100013, creature->GetGUID());
                    return true;
                    break;
 
                case 13: //Enchant waist
                    player->ADD_GOSSIP_ITEM(1, "EbonSteel Belt Buckle", GOSSIP_SENDER_MAIN, 158);
                    player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(100014, creature->GetGUID());
                    return true;
                    break;
 
                case 100:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_AVALANCHE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 101:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_ELEMENTAL_SLAYER);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 102:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_HEARTSONG);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 103:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_HURRICANE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 104:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_LANDSLIDE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 105:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_MENDING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 106:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_POWER_TORRENT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 107:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_WINDWALK);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 108:
                    mainItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                    if (mainItem->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
                    {
                        Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_2HWEP_MIGHTY_AGILITY);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        player->GetSession()->SendAreaTriggerMessage("|cffFF0000You don't have 2H equipped!");
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
 
                case 109:
                    mainItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                    if (mainItem->GetTemplate()->InventoryType == INVTYPE_SHIELD)
                    {
                        Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_SHIELD_MASTERY);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        player->GetSession()->SendAreaTriggerMessage("|cffFF0000You don't have Shield equipped!");
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
 
                case 110:
                    mainItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                    if (mainItem->GetTemplate()->InventoryType == INVTYPE_SHIELD)
                    {
                        Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_SHIELD_PROTECTION);
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else
                    {
                        player->GetSession()->SendAreaTriggerMessage("|cffFF0000You don't have Shield equipped!");
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
 
                case 111:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_OFF_HAND_SUPERIOR_INTELLECT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 112:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), ENCHANT_HEAD_VICIOUS_AGILITY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 113:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), ENCHANT_HEAD_VICIOUS_INTELLECT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 114:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), ENCHANT_HEAD_VICIOUS_STRENGTH);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 115:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), ENCHANT_SHOULDER_VICIOUS_AGILITY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 116:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), ENCHANT_SHOULDER_VICIOUS_INTELLECT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 117:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), ENCHANT_SHOULDER_VICIOUS_STRENGTH);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 118:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_GREATER_CRITICAL_STRIKE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 119:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_GREATER_INTELLECT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 120:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_GREATER_SPELL_PIERCING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 121:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_PROTECTION);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 122:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_EXCEPTIONAL_SPIRIT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 123:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_GREATER_STAMINA);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 124:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_MIGHTY_RESILIENCE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 125:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_PEERLESS_STATS);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 126:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_AGILITY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 127:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_EXCEPTIONAL_SPIRIT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 128:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_GREATER_CRITICAL_STRIKE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 129:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_GREATER_EXPERTISE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 130:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_GREATER_SPEED);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 131:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_MAJOR_STRENGTH);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 132:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_MIGHTY_INTELLECT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case 133:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_PRECISION);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case 134:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_SUPERIOR_DODGE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 135:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_GREATER_EXPERTISE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 136:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_GREATER_MASTERY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 137:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_HASTE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 138:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_MIGHTY_STRENGTH);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 139:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_ASSASSINS_STEP);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 140:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_HASTE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 141:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_LAVAWALKER);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 142:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_MAJOR_AGILITY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 143:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_MASTERY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 144:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_PRECISION);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 145:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), ENCHANT_RING_AGILITY);
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), ENCHANT_RING_AGILITY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 146:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), ENCHANT_RING_GREATER_STAMINA);
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), ENCHANT_RING_GREATER_STAMINA);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 147:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), ENCHANT_RING_INTELLECT);
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), ENCHANT_RING_INTELLECT);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 148:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), ENCHANT_RING_STRENGTH);
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), ENCHANT_RING_STRENGTH);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
 
                case 151:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), ENCHANT_LEGS_DRAGONSCALE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 152:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), ENCHANT_LEGS_CHARSCALE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 153:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), ENCHANT_LEGS_DRAKEHIDE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
       
                case 154:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), ENCHAANT_POWERFUL_GHOSTLY_THREAD);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 155:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), ENCHAANT_POWERFUL_ENCHANTED_THREAD);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 156:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOACK_AGILITY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 157:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_AGILITY);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 158:
                    PrismaticEnchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), ENCHANT_WAIST_BUCKLE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 149:
                    if (player->GetMoney() < OFF_PIECES_COST) {
                        ChatHandler(player->GetSession()).PSendSysMessage("You don't have enough money to purchase this! It costs %d gold", MAIN_PIECES_COST);
                        player->CLOSE_GOSSIP_MENU();;
                        break;
                    }
               
                /*Runeforge*/
                //Main hand
                case 160:
                    player->ADD_GOSSIP_ITEM(1, "Rune of Cinderglacier", GOSSIP_SENDER_MAIN, 162);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Lichbane", GOSSIP_SENDER_MAIN, 163);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Razorice", GOSSIP_SENDER_MAIN, 164);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Spellbreaking", GOSSIP_SENDER_MAIN, 165);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Spellshattering", GOSSIP_SENDER_MAIN, 166);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Swordbreaking", GOSSIP_SENDER_MAIN, 167);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Swordshattering", GOSSIP_SENDER_MAIN, 168);
                    player->ADD_GOSSIP_ITEM(1, "Rune of the Fallen Crusader", GOSSIP_SENDER_MAIN, 169);
                    player->ADD_GOSSIP_ITEM(1, "Rune of the Nerubian Carapace", GOSSIP_SENDER_MAIN, 170);
                    player->ADD_GOSSIP_ITEM(1, "Rune of the Stoneskin Gargoyle", GOSSIP_SENDER_MAIN, 171);
                    player->PlayerTalkClass->SendGossipMenu(100016, creature->GetGUID());
                    return true;
                    break;
 
                //Offhand
                case 161:
                    player->ADD_GOSSIP_ITEM(1, "Rune of Cinderglacier", GOSSIP_SENDER_MAIN, 172);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Lichbane", GOSSIP_SENDER_MAIN, 173);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Razorice", GOSSIP_SENDER_MAIN, 174);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Spellbreaking", GOSSIP_SENDER_MAIN, 175);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Spellshattering", GOSSIP_SENDER_MAIN, 176);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Swordbreaking", GOSSIP_SENDER_MAIN, 177);
                    player->ADD_GOSSIP_ITEM(1, "Rune of Swordshattering", GOSSIP_SENDER_MAIN, 178);
                    player->ADD_GOSSIP_ITEM(1, "Rune of the Fallen Crusader", GOSSIP_SENDER_MAIN, 179);
                    player->ADD_GOSSIP_ITEM(1, "Rune of the Nerubian Carapace", GOSSIP_SENDER_MAIN, 180);
                    player->ADD_GOSSIP_ITEM(1, "Rune of the Stoneskin Gargoyle", GOSSIP_SENDER_MAIN, 181);
                    player->PlayerTalkClass->SendGossipMenu(100017, creature->GetGUID());
                    return true;
                    break;
                    /*Runeforge Mainhand*/
                case 162:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_CINDERGLAICER);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 163:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_LICHBANE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 164:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_RAZORICE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 165:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_SPELLBREAKING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 166:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_SPELLSHATTERING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 167:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_SWORDBREAKING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 168:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFROGE_SWORDSHATTERING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 169:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_FALLEN_CRUSADE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 170:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_NERUBIAN_CARAPACE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 171:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), RUNEFORGE_STONESKIN_GARGYOLE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                /*Runeforge offhand*/
               
                case 172:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_CINDERGLAICER);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 173:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_LICHBANE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 174:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_RAZORICE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 175:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_SPELLBREAKING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 176:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_SPELLSHATTERING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 177:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_SWORDBREAKING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 178:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFROGE_SWORDSHATTERING);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 179:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_FALLEN_CRUSADE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 180:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_NERUBIAN_CARAPACE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 181:
                    Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), RUNEFORGE_STONESKIN_GARGYOLE);
                    player->CLOSE_GOSSIP_MENU();
                    break;
 
                case 300:
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Weapon]", GOSSIP_SENDER_MAIN, 1);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant 2H Weapon]", GOSSIP_SENDER_MAIN, 2);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Shield]", GOSSIP_SENDER_MAIN, 3);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Head]", GOSSIP_SENDER_MAIN, 4);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Shoulders]", GOSSIP_SENDER_MAIN, 5);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Cloak]", GOSSIP_SENDER_MAIN, 6);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Chest]", GOSSIP_SENDER_MAIN, 7);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Bracers]", GOSSIP_SENDER_MAIN, 8);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Gloves]", GOSSIP_SENDER_MAIN, 9);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Legs]", GOSSIP_SENDER_MAIN, 10);
                    player->ADD_GOSSIP_ITEM(1, "[Enchant Feet]", GOSSIP_SENDER_MAIN, 11);
 
                    if (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) == 450)
                        player->ADD_GOSSIP_ITEM(1, "[Enchant Rings]", GOSSIP_SENDER_MAIN, 12);
 
                    player->PlayerTalkClass->SendGossipMenu(100001, creature->GetGUID());
                    break;
 
            }
 
            return true;
        }
 
 
};
 
void AddSC_npc_enchantment()
{
  new npc_enchantment();
}
