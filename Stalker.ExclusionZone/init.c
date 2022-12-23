void main()

{

	//INIT WEATHER BEFORE ECONOMY INIT------------------------

	Weather weather = g_Game.GetWeather();



	weather.MissionWeather(false);    // false = use weather controller from Weather.c



	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);

	weather.GetRain().Set( 0, 0, 1);

	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);



	//INIT ECONOMY--------------------------------------

	Hive ce = CreateHive();

	if ( ce )

		ce.InitOffline();



	//DATE RESET AFTER ECONOMY INIT-------------------------

	int year, month, day, hour, minute;

	int reset_month = 9, reset_day = 20;

	GetGame().GetWorld().GetDate(year, month, day, hour, minute);



	if ((month == reset_month) && (day < reset_day))

	{

		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);

	}

	else

	{

		if ((month == reset_month + 1) && (day > reset_day))

		{

			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);

		}

		else

		{

			if ((month < reset_month) || (month > reset_month + 1))

			{

				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);

			}

		}

	}

}



class CustomMission: MissionServer

{

	void SetRandomHealth(EntityAI itemEnt)

	{

		if ( itemEnt )

		{

			float rndHlt = Math.RandomFloat( 0.45, 0.65 );

			itemEnt.SetHealth01( "", "", rndHlt );

		}

	}



	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)

	{

		Entity playerEnt;

		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );

		Class.CastTo( m_player, playerEnt );



		GetGame().SelectPlayer( identity, m_player );



		return m_player;

	}



	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)

	{

		EntityAI itemClothing;

		EntityAI itemEnt;

		ItemBase itemBs;

		float rand;



		itemClothing = player.FindAttachmentBySlotName( "Body" );

		if ( itemClothing )

		{

			SetRandomHealth( itemClothing );

			

			//ШМОТ
			//Рюкзак
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Bridger_AoD_Back" );
			itemBs = ItemBase.Cast(itemEnt);

			//Ботинки
			itemEnt = itemClothing.GetInventory().CreateInInventory( "WorkingBoots_Beige" );
                	itemBs = ItemBase.Cast(itemEnt);

			//Худи
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Hoodie_Green" );
                	itemBs = ItemBase.Cast(itemEnt);

			//Кепка
			itemEnt = itemClothing.GetInventory().CreateInInventory( "BaseballCap_Camo" );
                	itemBs = ItemBase.Cast(itemEnt);

			//Перчатки
			itemEnt = itemClothing.GetInventory().CreateInInventory( "WorkingGloves_Black" );
                	itemBs = ItemBase.Cast(itemEnt);

			//Джинсы
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Jeans_Brown" );
                	itemBs = ItemBase.Cast(itemEnt);


			//ОРУЖИЕ
			//Обрез
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Toz66Obrez_AoD" );
	                itemBs = ItemBase.Cast(itemEnt);

			//Патроны
			itemEnt = itemClothing.GetInventory().CreateInInventory( "AmmoBox_00buck_10rnd" );
	                if ( Class.CastTo( itemBs, itemEnt ) )
                                itemBs.SetQuantity( 7 );//Количество


			//ЕДА
			//Сало
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Lard" );
        	        itemBs = ItemBase.Cast(itemEnt);

			//Мармелад
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Marmelade" );
        	        itemBs = ItemBase.Cast(itemEnt);

			itemEnt = itemClothing.GetInventory().CreateInInventory( "SardinesCan" );
	                itemBs = ItemBase.Cast(itemEnt);

			//Бутылка воды
			itemEnt = itemClothing.GetInventory().CreateInInventory( "WaterBottle" );
	                itemBs = ItemBase.Cast(itemEnt);


			SetRandomHealth( itemEnt );

		}

		

		itemClothing = player.FindAttachmentBySlotName( "Legs" );

		if ( itemClothing )

			SetRandomHealth( itemClothing );

		

		itemClothing = player.FindAttachmentBySlotName( "Feet" );

	}

};



Mission CreateCustomMission(string path)

{

	return new CustomMission();

}
