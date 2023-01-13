class StartSetsPlayersConfig
{	
	void StartSetsPlayer(PlayerBase player,int use_set_id)
	{
		EntityAI itemCreated = NULL;
		EntityAI itemCreated1 = NULL;
		ItemBase itemCasted = NULL;
		
		switch( use_set_id ) //Раздаем лут (можно использовать значения от 1 и выше, только не 0 и не -1)
		{
			case 1: //Set with number 1 (Сет с номером 1)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
				itemCreated = player.GetInventory().CreateInInventory("MountainBag_Green"); 	        // Выдаем рюкзак и записываем в переменную itemCreated
				if (itemCreated)															            // Проверяем, создался ли рюкзак. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
				{                                                                                       
					SetRandomHealthItem(itemCreated);										            // Выдаем рюкзаку рандомное качество
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");	            // Добавляем в инвентарь созданного рюкзака яблоко и записываем в переменную itemCreated1
					if (itemCreated1)														            // Проверяем, создалось ли яблоко в рюкзаке, яблоко у нас с переменной itemCreated1
					{                                                                                   
						SetRandomHealthItem(itemCreated1);									            // Выдаем яблоку рандомное качество
					}                                                                                   
					itemCreated1 = NULL;													            // Обнуляем значение переменной после работы с ней, чтобы следующая проверка прошла корректно
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");		            // Выдаем игроку бинты в рюкзак и записываем в переменную itemCreated1
					if (itemCreated1)														            // Проверяем, создались ли бинты в рюкзаке, они у нас с переменной itemCreated1
					{                                                                                   
						itemCasted = ItemBase.Cast(itemCreated1);							            // Выполняем преобразование в другой класс для работы с нужной нам функцией, поскольку в классе EntityAI нет нужной нам функции SetQuantity, а в подклассе ItemBase она есть. Предмет при этом так и остается один и тот же!
						itemCasted.SetQuantity(4);											            // Определяем количество для созданных бинтов как 4 штуки
						SetRandomHealthItem(itemCreated);									            // Выдаем бинтам рандомное качество, функция работает с классом EntityAI (см. в конфе файла)
					}
				}
				// переменную itemCreated не обнуляем далее, поскольку мы ее не используем в проверке ниже.
		        itemCreated = player.GetInventory().CreateInInventory("SantasHat");            	        // Выдаем игроку головной убор
				itemCreated = player.GetInventory().CreateInInventory("SantasBeard");            	    // Выдаем игроку маску
		        itemCreated = player.GetInventory().CreateInInventory("OMNOGloves_Gray");		        // Выдаем игроку перчатки
				itemCreated = player.GetInventory().CreateInInventory("TrackSuitPants_Green");		    // Выдаем игроку штаны
				itemCreated = player.GetInventory().CreateInInventory("Sneakers_Green");	            // Выдаем игроку обувь
				itemCreated = player.GetInventory().CreateInInventory("ChernarusSportShirt");	        // Выдаем игроку куртку				
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("PlateCarrierVest"); 	            // Выдаем броню
				if (itemCreated)															            // Проверяем, создаласи ли броня. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 			    // Выдаем кобуру и крепим
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierPouches" ); 		        // Выдаем карманы и крепим
					
				}
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MilitaryBelt"); 	                // Выдаем ремень
				if (itemCreated)															            // Проверяем, создался ли ремень. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "NylonKnifeSheath" ); 			        // Выдаем ножны и крепим
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 		        // Выдаем кобуру и крепим
					
				}
				itemCreated = NULL;
				//itemCasted = ItemBase.Cast(itemCreated);									            // Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		            // Выдаем игроку ножик в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("MKII");				            // Выдаем игроку MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_MKII_10Rnd");	            // Выдаем игроку магазины к MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_MKII_10Rnd");	            // Выдаем игроку магазины к MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
				itemCreated = NULL;															            // Обнуляем значение переменной после работы с ней, нужно если мы будем использовать ее далее
				itemCreated = player.GetHumanInventory().CreateInHands("akm");				            // Выдаем игроку AKM в руки
				if (itemCreated)															            // Проверяем, создался ли АКМ
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 			            // Выдаем игроку на AKM оптику ПСО 11 и крепим
					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 		            // Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );			            // Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );			            // Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
				}					
				break;
			}
			
			case 2: //Set with number 2  (Сет с номером 2)
			{
				break;
			}
			
			case 3: //Set with number 3   (Сет с номером 3)
			{
				break;
			}
			
			case 4: //Set with number 4   (Сет с номером 4)
			{
				break;
			}
			
			case 5: //Set with number 5   (Сет с номером 5)
			{
				break;
			}
			
			case 6: //Set with number 6   (Сет с номером 6)
			{
				break;
			}
			
			default: //Default starting spawn set (Сет поумолчанию для всех игроков, если хотите назначить - добавляйте здесь!)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
				//DefaultSets(player); // Для выдачи своих сетов по рандому всем игрокам, не прописанным в скрипте, раскомментировать эту строку
				itemCreated = player.GetInventory().CreateInInventory("Bridger_AoD_Back"); 	        // Выдаем рюкзак и записываем в переменную itemCreated
				if (itemCreated)															            // Проверяем, создался ли рюкзак. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
				{                                                                                       
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");		            // Выдаем игроку бинты в рюкзак и записываем в переменную itemCreated1
					if (itemCreated1)														            // Проверяем, создались ли бинты в рюкзаке, они у нас с переменной itemCreated1
					{                                                                                   
						itemCasted = ItemBase.Cast(itemCreated1);							            // Выполняем преобразование в другой класс для работы с нужной нам функцией, поскольку в классе EntityAI нет нужной нам функции SetQuantity, а в подклассе ItemBase она есть. Предмет при этом так и остается один и тот же!
						itemCasted.SetQuantity(4);											            // Определяем количество для созданных бинтов как 4 штуки
						SetRandomHealthItem(itemCreated);									            // Выдаем бинтам рандомное качество, функция работает с классом EntityAI (см. в конфе файла)
					}
				}
				itemCreated = player.GetInventory().CreateInInventory("WaterBottle");            	    // Выдаем игроку воду в бутылке
				itemCreated = player.GetInventory().CreateInInventory("SardinesCan");	                // Добавляем в инвентарь созданного рюкзака сардины и записываем в переменную itemCreated1
				// переменную itemCreated не обнуляем далее, поскольку мы ее не используем в проверке ниже.
		        itemCreated = player.GetInventory().CreateInInventory("BaseballCap_Camo");            	// Выдаем игроку головной убор
		        itemCreated = player.GetInventory().CreateInInventory("WorkingGloves_Black");		    // Выдаем игроку перчатки
				itemCreated = player.GetInventory().CreateInInventory("Jeans_Brown");		            // Выдаем игроку штаны
				itemCreated = player.GetInventory().CreateInInventory("WorkingBoots_Beige");	        // Выдаем игроку обувь
				itemCreated = player.GetInventory().CreateInInventory("Hoodie_Green");	                // Выдаем игроку куртку				
				itemCreated = NULL;
				//itemCasted = ItemBase.Cast(itemCreated);									            // Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		            // Выдаем игроку ножик в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");		    // Выдаем игроку патроны к обрезу в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");		    // Выдаем игроку патроны к обрезу в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");		    // Выдаем игроку патроны к обрезу в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");		    // Выдаем игроку патроны к обрезу в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");		    // Выдаем игроку патроны к обрезу в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");		    // Выдаем игроку патроны к обрезу в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");		    // Выдаем игроку патроны к обрезу в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Chemlight_Green");		        // Выдаем игроку химсвет в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Marmelade");            	        // Выдаем игроку мармелад
				itemCreated = NULL;															            // Обнуляем значение переменной после работы с ней, нужно если мы будем использовать ее далее
				itemCreated = player.GetHumanInventory().CreateInHands("Toz66Obrez_AoD");				// Выдаем игроку ТОЗ в руки
				break;
			}
		}
	}
	
	void SetRandomHealthItem(EntityAI itemCreated) // Функция генерирует и применяет для предмета рандомное значение здоровья!
	{
		if ( itemCreated )
		{
			private int rndHlt = Math.RandomInt(55,6);
			itemCreated.SetHealth("","",rndHlt);
		}
	}
	
	void DefaultSets(PlayerBase player) // Функция выдает сеты игрокам, не прописанным в конфигурации скрипта!!!
	{
		EntityAI itemCreated = NULL;
		EntityAI itemCreated1 = NULL;
		ItemBase itemCasted = NULL;
		
		// ниже пример, если вам нужно задать свои точки спавна для всех игроков. Этот код можно также использовать и для каждого сета индивидуально!
		// Код закомментирован, если это надо - раскомментируйте!
		// начало кода точек спавна игрока
		/*
		private array <vector>  spawnpoints = {"7500 0 7500",
			"7500 0 7500","7500 0 7500",
			"7500 0 7500"};
		private vector selected_spawnpoint = spawnpoints.GetRandomElement();
		player.SetPosition(selected_spawnpoint);
		*/
		// конец кода точек спавна игрока
		
		private int random_set_number = Math.RandomIntInclusive(1,3); // генерируем рандом номер сета от 1 до 6 включительно (по значениям блоков case ниже)
		switch( random_set_number ) //Раздаем лут (можно использовать значения от 1 и выше, только не 0 и не -1)
		{
			case 1: //Set with number 1 (Ñåò ñ íîìåðîì 1)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // ×òîáû óäàëèòü ñ ïåðñîíàæà óæå èìåþùèåñÿ ñòàíäàðòíûå ñòàðòîâûå øìîòêè ðàñêîììåíòèðîâàòü ñòðîêó
				itemCreated = player.GetInventory().CreateInInventory("MountainBag_Green"); 	        // Âûäàåì ðþêçàê è çàïèñûâàåì â ïåðåìåííóþ itemCreated
				if (itemCreated)															            // Ïðîâåðÿåì, ñîçäàëñÿ ëè ðþêçàê. Åñëè îí ñîçäàëñÿ, ïåðåìåííàÿ itemCreated áóäåò íå ïóñòà è ïðîâåðêà ïðîéäåò
				{                                                                                       
					SetRandomHealthItem(itemCreated);										            // Âûäàåì ðþêçàêó ðàíäîìíîå êà÷åñòâî
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");	            // Äîáàâëÿåì â èíâåíòàðü ñîçäàííîãî ðþêçàêà ÿáëîêî è çàïèñûâàåì â ïåðåìåííóþ itemCreated1
					if (itemCreated1)														            // Ïðîâåðÿåì, ñîçäàëîñü ëè ÿáëîêî â ðþêçàêå, ÿáëîêî ó íàñ ñ ïåðåìåííîé itemCreated1
					{                                                                                   
						SetRandomHealthItem(itemCreated1);									            // Âûäàåì ÿáëîêó ðàíäîìíîå êà÷åñòâî
					}                                                                                   
					itemCreated1 = NULL;													            // Îáíóëÿåì çíà÷åíèå ïåðåìåííîé ïîñëå ðàáîòû ñ íåé, ÷òîáû ñëåäóþùàÿ ïðîâåðêà ïðîøëà êîððåêòíî
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");		            // Âûäàåì èãðîêó áèíòû â ðþêçàê è çàïèñûâàåì â ïåðåìåííóþ itemCreated1
					if (itemCreated1)														            // Ïðîâåðÿåì, ñîçäàëèñü ëè áèíòû â ðþêçàêå, îíè ó íàñ ñ ïåðåìåííîé itemCreated1
					{                                                                                   
						itemCasted = ItemBase.Cast(itemCreated1);							            // Âûïîëíÿåì ïðåîáðàçîâàíèå â äðóãîé êëàññ äëÿ ðàáîòû ñ íóæíîé íàì ôóíêöèåé, ïîñêîëüêó â êëàññå EntityAI íåò íóæíîé íàì ôóíêöèè SetQuantity, à â ïîäêëàññå ItemBase îíà åñòü. Ïðåäìåò ïðè ýòîì òàê è îñòàåòñÿ îäèí è òîò æå!
						itemCasted.SetQuantity(4);											            // Îïðåäåëÿåì êîëè÷åñòâî äëÿ ñîçäàííûõ áèíòîâ êàê 4 øòóêè
						SetRandomHealthItem(itemCreated);									            // Âûäàåì áèíòàì ðàíäîìíîå êà÷åñòâî, ôóíêöèÿ ðàáîòàåò ñ êëàññîì EntityAI (ñì. â êîíôå ôàéëà)
					}
				}
				// ïåðåìåííóþ itemCreated íå îáíóëÿåì äàëåå, ïîñêîëüêó ìû åå íå èñïîëüçóåì â ïðîâåðêå íèæå.
		        itemCreated = player.GetInventory().CreateInInventory("SantasHat");            	        // Âûäàåì èãðîêó ãîëîâíîé óáîð
				itemCreated = player.GetInventory().CreateInInventory("SantasBeard");            	    // Âûäàåì èãðîêó ìàñêó
		        itemCreated = player.GetInventory().CreateInInventory("OMNOGloves_Gray");		        // Âûäàåì èãðîêó ïåð÷àòêè
				itemCreated = player.GetInventory().CreateInInventory("TrackSuitPants_Green");		    // Âûäàåì èãðîêó øòàíû
				itemCreated = player.GetInventory().CreateInInventory("Sneakers_Green");	            // Âûäàåì èãðîêó îáóâü
				itemCreated = player.GetInventory().CreateInInventory("ChernarusSportShirt");	        // Âûäàåì èãðîêó êóðòêó				
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("PlateCarrierVest"); 	            // Âûäàåì áðîíþ
				if (itemCreated)															            // Ïðîâåðÿåì, ñîçäàëàñè ëè áðîíÿ. Åñëè îí ñîçäàëñÿ, ïåðåìåííàÿ itemCreated áóäåò íå ïóñòà è ïðîâåðêà ïðîéäåò
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 			    // Âûäàåì êîáóðó è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierPouches" ); 		        // Âûäàåì êàðìàíû è êðåïèì
					
				}
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MilitaryBelt"); 	                // Âûäàåì ðåìåíü
				if (itemCreated)															            // Ïðîâåðÿåì, ñîçäàëñÿ ëè ðåìåíü. Åñëè îí ñîçäàëñÿ, ïåðåìåííàÿ itemCreated áóäåò íå ïóñòà è ïðîâåðêà ïðîéäåò
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "NylonKnifeSheath" ); 			        // Âûäàåì íîæíû è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 		        // Âûäàåì êîáóðó è êðåïèì
					
				}
				itemCreated = NULL;
				//itemCasted = ItemBase.Cast(itemCreated);									            // Ñòðîêà íå íóæíà, çàêîìåíòèðîâàíà. èñïîëüçóåòñÿ äëÿ èçìåíåíèÿ êëàññà EntityAI â ItemBase (÷òîáû íóæíûå îïåðàöèè áûëè äîñòóïíû)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		            // Âûäàåì èãðîêó íîæèê â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("MKII");				            // Âûäàåì èãðîêó MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_MKII_10Rnd");	            // Âûäàåì èãðîêó ìàãàçèíû ê MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_MKII_10Rnd");	            // Âûäàåì èãðîêó ìàãàçèíû ê MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // Âûäàåì èãðîêó ìàãàçèíû ê AKM â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // Âûäàåì èãðîêó ìàãàçèíû ê AKM â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = NULL;															            // Îáíóëÿåì çíà÷åíèå ïåðåìåííîé ïîñëå ðàáîòû ñ íåé, íóæíî åñëè ìû áóäåì èñïîëüçîâàòü åå äàëåå
				itemCreated = player.GetHumanInventory().CreateInHands("akm");				            // Âûäàåì èãðîêó AKM â ðóêè
				if (itemCreated)															            // Ïðîâåðÿåì, ñîçäàëñÿ ëè ÀÊÌ
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 			            // Âûäàåì èãðîêó íà AKM îïòèêó ÏÑÎ 11 è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 		            // Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );			            // Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );			            // Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
				}					
				break;
			}
			
			case 2: //Set with number 2  (Ñåò ñ íîìåðîì 2)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // ×òîáû óäàëèòü ñ ïåðñîíàæà óæå èìåþùèåñÿ ñòàíäàðòíûå ñòàðòîâûå øìîòêè ðàñêîììåíòèðîâàòü ñòðîêó
				itemCreated = player.GetInventory().CreateInInventory("MountainBag_Green"); 	            // Âûäàåì ðþêçàê è çàïèñûâàåì â ïåðåìåííóþ itemCreated
				if (itemCreated)															            // Ïðîâåðÿåì, ñîçäàëñÿ ëè ðþêçàê. Åñëè îí ñîçäàëñÿ, ïåðåìåííàÿ itemCreated áóäåò íå ïóñòà è ïðîâåðêà ïðîéäåò
				{                                                                                       
					SetRandomHealthItem(itemCreated);										            // Âûäàåì ðþêçàêó ðàíäîìíîå êà÷åñòâî
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");	            // Äîáàâëÿåì â èíâåíòàðü ñîçäàííîãî ðþêçàêà ÿáëîêî è çàïèñûâàåì â ïåðåìåííóþ itemCreated1
					if (itemCreated1)														            // Ïðîâåðÿåì, ñîçäàëîñü ëè ÿáëîêî â ðþêçàêå, ÿáëîêî ó íàñ ñ ïåðåìåííîé itemCreated1
					{                                                                                   
						SetRandomHealthItem(itemCreated1);									            // Âûäàåì ÿáëîêó ðàíäîìíîå êà÷åñòâî
					}                                                                                   
					itemCreated1 = NULL;													            // Îáíóëÿåì çíà÷åíèå ïåðåìåííîé ïîñëå ðàáîòû ñ íåé, ÷òîáû ñëåäóþùàÿ ïðîâåðêà ïðîøëà êîððåêòíî
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");		            // Âûäàåì èãðîêó áèíòû â ðþêçàê è çàïèñûâàåì â ïåðåìåííóþ itemCreated1
					if (itemCreated1)														            // Ïðîâåðÿåì, ñîçäàëèñü ëè áèíòû â ðþêçàêå, îíè ó íàñ ñ ïåðåìåííîé itemCreated1
					{                                                                                   
						itemCasted = ItemBase.Cast(itemCreated1);							            // Âûïîëíÿåì ïðåîáðàçîâàíèå â äðóãîé êëàññ äëÿ ðàáîòû ñ íóæíîé íàì ôóíêöèåé, ïîñêîëüêó â êëàññå EntityAI íåò íóæíîé íàì ôóíêöèè SetQuantity, à â ïîäêëàññå ItemBase îíà åñòü. Ïðåäìåò ïðè ýòîì òàê è îñòàåòñÿ îäèí è òîò æå!
						itemCasted.SetQuantity(4);											            // Îïðåäåëÿåì êîëè÷åñòâî äëÿ ñîçäàííûõ áèíòîâ êàê 4 øòóêè
						SetRandomHealthItem(itemCreated);									            // Âûäàåì áèíòàì ðàíäîìíîå êà÷åñòâî, ôóíêöèÿ ðàáîòàåò ñ êëàññîì EntityAI (ñì. â êîíôå ôàéëà)
					}
				}
				// ïåðåìåííóþ itemCreated íå îáíóëÿåì äàëåå, ïîñêîëüêó ìû åå íå èñïîëüçóåì â ïðîâåðêå íèæå.
		        itemCreated = player.GetInventory().CreateInInventory("SantasHat");            	        // Âûäàåì èãðîêó ãîëîâíîé óáîð
				itemCreated = player.GetInventory().CreateInInventory("SantasBeard");            	    // Âûäàåì èãðîêó ìàñêó
		        itemCreated = player.GetInventory().CreateInInventory("OMNOGloves_Gray");		        // Âûäàåì èãðîêó ïåð÷àòêè
				itemCreated = player.GetInventory().CreateInInventory("TrackSuitPants_Green");		    // Âûäàåì èãðîêó øòàíû
				itemCreated = player.GetInventory().CreateInInventory("Sneakers_Green");	            // Âûäàåì èãðîêó îáóâü
				itemCreated = player.GetInventory().CreateInInventory("ChernarusSportShirt");	        // Âûäàåì èãðîêó êóðòêó				
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("PlateCarrierVest"); 	            // Âûäàåì áðîíþ
				if (itemCreated)															            // Ïðîâåðÿåì, ñîçäàëàñè ëè áðîíÿ. Åñëè îí ñîçäàëñÿ, ïåðåìåííàÿ itemCreated áóäåò íå ïóñòà è ïðîâåðêà ïðîéäåò
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 			    // Âûäàåì êîáóðó è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierPouches" ); 		        // Âûäàåì êàðìàíû è êðåïèì
					
				}
				itemCreated = NULL;
				//itemCasted = ItemBase.Cast(itemCreated);									            // Ñòðîêà íå íóæíà, çàêîìåíòèðîâàíà. èñïîëüçóåòñÿ äëÿ èçìåíåíèÿ êëàññà EntityAI â ItemBase (÷òîáû íóæíûå îïåðàöèè áûëè äîñòóïíû)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		            // Âûäàåì èãðîêó íîæèê â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // Âûäàåì èãðîêó ìàãàçèíû ê AKM â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // Âûäàåì èãðîêó ìàãàçèíû ê AKM â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = NULL;															            // Îáíóëÿåì çíà÷åíèå ïåðåìåííîé ïîñëå ðàáîòû ñ íåé, íóæíî åñëè ìû áóäåì èñïîëüçîâàòü åå äàëåå
				itemCreated = player.GetHumanInventory().CreateInHands("akm");				            // Âûäàåì èãðîêó AKM â ðóêè
				if (itemCreated)															            // Ïðîâåðÿåì, ñîçäàëñÿ ëè ÀÊÌ
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 			            // Âûäàåì èãðîêó íà AKM îïòèêó ÏÑÎ 11 è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 		            // Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );			            // Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );			            // Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
				}					
				break;
			}
			
			case 3: //Set with number 3   (Ñåò ñ íîìåðîì 3)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // ×òîáû óäàëèòü ñ ïåðñîíàæà óæå èìåþùèåñÿ ñòàíäàðòíûå ñòàðòîâûå øìîòêè ðàñêîììåíòèðîâàòü ñòðîêó
				itemCreated = player.GetInventory().CreateInInventory("CoyoteBag_Green"); 	// Âûäàåì ðþêçàê è çàïèñûâàåì â ïåðåìåííóþ itemCreated
				if (itemCreated)															// Ïðîâåðÿåì, ñîçäàëñÿ ëè ðþêçàê. Åñëè îí ñîçäàëñÿ, ïåðåìåííàÿ itemCreated áóäåò íå ïóñòà è ïðîâåðêà ïðîéäåò
				{
					SetRandomHealthItem(itemCreated);												// Âûäàåì ðþêçàêó ðàíäîìíîå êà÷åñòâî
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");			// Äîáàâëÿåì â èíâåíòàðü ñîçäàííîãî ðþêçàêà ÿáëîêî è çàïèñûâàåì â ïåðåìåííóþ itemCreated1
					if (itemCreated1)																// Ïðîâåðÿåì, ñîçäàëîñü ëè ÿáëîêî â ðþêçàêå, ÿáëîêî ó íàñ ñ ïåðåìåííîé itemCreated1
					{
						SetRandomHealthItem(itemCreated1);												// Âûäàåì ÿáëîêó ðàíäîìíîå êà÷åñòâî
					}
					itemCreated1 = NULL;															// Îáíóëÿåì çíà÷åíèå ïåðåìåííîé ïîñëå ðàáîòû ñ íåé, ÷òîáû ñëåäóþùàÿ ïðîâåðêà ïðîøëà êîððåêòíî
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");				// Âûäàåì èãðîêó áèíòû â ðþêçàê è çàïèñûâàåì â ïåðåìåííóþ itemCreated1
					if (itemCreated1)																// Ïðîâåðÿåì, ñîçäàëèñü ëè áèíòû â ðþêçàêå, îíè ó íàñ ñ ïåðåìåííîé itemCreated1
					{
						itemCasted = ItemBase.Cast(itemCreated1);										// Âûïîëíÿåì ïðåîáðàçîâàíèå â äðóãîé êëàññ äëÿ ðàáîòû ñ íóæíîé íàì ôóíêöèåé, ïîñêîëüêó â êëàññå EntityAI íåò íóæíîé íàì ôóíêöèè SetQuantity, à â ïîäêëàññå ItemBase îíà åñòü. Ïðåäìåò ïðè ýòîì òàê è îñòàåòñÿ îäèí è òîò æå!
						itemCasted.SetQuantity(4);														// Îïðåäåëÿåì êîëè÷åñòâî äëÿ ñîçäàííûõ áèíòîâ êàê 4 øòóêè
						SetRandomHealthItem(itemCreated);												// Âûäàåì áèíòàì ðàíäîìíîå êà÷åñòâî, ôóíêöèÿ ðàáîòàåò ñ êëàññîì EntityAI (ñì. â êîíôå ôàéëà)
					}
				}
				// ïåðåìåííóþ itemCreated íå îáíóëÿåì äàëåå, ïîñêîëüêó ìû åå íå èñïîëüçóåì â ïðîâåðêå íèæå.
				itemCreated = player.GetInventory().CreateInInventory("TTSKOPants");		// Âûäàåì èãðîêó øòàíû
				itemCreated = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");	// Âûäàåì èãðîêó êóðòêó
				itemCreated = player.GetInventory().CreateInInventory("CombatBoots_Black");	// Âûäàåì èãðîêó îáóâü
				//itemCasted = ItemBase.Cast(itemCreated);										// Ñòðîêà íå íóæíà, çàêîìåíòèðîâàíà. èñïîëüçóåòñÿ äëÿ èçìåíåíèÿ êëàññà EntityAI â ItemBase (÷òîáû íóæíûå îïåðàöèè áûëè äîñòóïíû)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		// Âûäàåì èãðîêó íîæèê â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("FNX45");				// Âûäàåì èãðîêó FNX â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Âûäàåì èãðîêó ìàãàçèíû ê FNX â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Âûäàåì èãðîêó ìàãàçèíû ê FNX â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		// Âûäàåì èãðîêó ìàãàçèíû ê AKM â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		// Âûäàåì èãðîêó ìàãàçèíû ê AKM â ëþáîé ñâîáîäíûé ñëîò â èíâåíòàðå
				itemCreated = NULL;															// Îáíóëÿåì çíà÷åíèå ïåðåìåííîé ïîñëå ðàáîòû ñ íåé, íóæíî åñëè ìû áóäåì èñïîëüçîâàòü åå äàëåå
				itemCreated = player.GetHumanInventory().CreateInHands("akm");				// Âûäàåì èãðîêó AKM â ðóêè
				if (itemCreated)															// Ïðîâåðÿåì, ñîçäàëñÿ ëè ÀÊÌ
				{
					itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 				// Âûäàåì èãðîêó íà AKM îïòèêó ÏÑÎ 11 è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 			// Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );				// Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );				// Âûäàåì èãðîêó íà AKM öåâüå, ïðèêëàä è ãëóøèòåëü, è êðåïèì
				}					
				break;
			}
			
			case 4: //Set with number 4   (Ñåò ñ íîìåðîì 4)
			{
				break;
			}
			
			case 5: //Set with number 5   (Ñåò ñ íîìåðîì 5)
			{
				break;
			}
			
			case 6: //Set with number 6   (Ñåò ñ íîìåðîì 6)
			{
				break;
			}
			
			default: //Default starting spawn set (Сет поумолчанию для всех игроков, в случае если ни один из сетов выше не выпал)
			{
				//My_Custom_Spawn_Parameters.RemoveAllItems(player); // ×òîáû óäàëèòü ñ ïåðñîíàæà óæå èìåþùèåñÿ ñòàíäàðòíûå ñòàðòîâûå øìîòêè ðàñêîììåíòèðîâàòü ñòðîêó
				
				break;
			}
		}
	}
}
