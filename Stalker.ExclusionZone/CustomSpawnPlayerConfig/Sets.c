class StartSetsPlayersConfig
{	
	void StartSetsPlayer(PlayerBase player,int use_set_id)
	{
		EntityAI itemCreated = NULL;
		EntityAI itemCreated1 = NULL;
		ItemBase itemCasted = NULL;
		
		switch( use_set_id ) //������� ��� (����� ������������ �������� �� 1 � ����, ������ �� 0 � �� -1)
		{
			case 1: //Set with number 1 (��� � ������� 1)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // ����� ������� � ��������� ��� ��������� ����������� ��������� ������ ����������������� ������
				itemCreated = player.GetInventory().CreateInInventory("MountainBag_Green"); 	        // ������ ������ � ���������� � ���������� itemCreated
				if (itemCreated)															            // ���������, �������� �� ������. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{                                                                                       
					SetRandomHealthItem(itemCreated);										            // ������ ������� ��������� ��������
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");	            // ��������� � ��������� ���������� ������� ������ � ���������� � ���������� itemCreated1
					if (itemCreated1)														            // ���������, ��������� �� ������ � �������, ������ � ��� � ���������� itemCreated1
					{                                                                                   
						SetRandomHealthItem(itemCreated1);									            // ������ ������ ��������� ��������
					}                                                                                   
					itemCreated1 = NULL;													            // �������� �������� ���������� ����� ������ � ���, ����� ��������� �������� ������ ���������
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");		            // ������ ������ ����� � ������ � ���������� � ���������� itemCreated1
					if (itemCreated1)														            // ���������, ��������� �� ����� � �������, ��� � ��� � ���������� itemCreated1
					{                                                                                   
						itemCasted = ItemBase.Cast(itemCreated1);							            // ��������� �������������� � ������ ����� ��� ������ � ������ ��� ��������, ��������� � ������ EntityAI ��� ������ ��� ������� SetQuantity, � � ��������� ItemBase ��� ����. ������� ��� ���� ��� � �������� ���� � ��� ��!
						itemCasted.SetQuantity(4);											            // ���������� ���������� ��� ��������� ������ ��� 4 �����
						SetRandomHealthItem(itemCreated);									            // ������ ������ ��������� ��������, ������� �������� � ������� EntityAI (��. � ����� �����)
					}
				}
				// ���������� itemCreated �� �������� �����, ��������� �� �� �� ���������� � �������� ����.
		        itemCreated = player.GetInventory().CreateInInventory("SantasHat");            	        // ������ ������ �������� ����
				itemCreated = player.GetInventory().CreateInInventory("SantasBeard");            	    // ������ ������ �����
		        itemCreated = player.GetInventory().CreateInInventory("OMNOGloves_Gray");		        // ������ ������ ��������
				itemCreated = player.GetInventory().CreateInInventory("TrackSuitPants_Green");		    // ������ ������ �����
				itemCreated = player.GetInventory().CreateInInventory("Sneakers_Green");	            // ������ ������ �����
				itemCreated = player.GetInventory().CreateInInventory("ChernarusSportShirt");	        // ������ ������ ������				
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("PlateCarrierVest"); 	            // ������ �����
				if (itemCreated)															            // ���������, ��������� �� �����. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 			    // ������ ������ � ������
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierPouches" ); 		        // ������ ������� � ������
					
				}
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MilitaryBelt"); 	                // ������ ������
				if (itemCreated)															            // ���������, �������� �� ������. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "NylonKnifeSheath" ); 			        // ������ ����� � ������
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 		        // ������ ������ � ������
					
				}
				itemCreated = NULL;
				//itemCasted = ItemBase.Cast(itemCreated);									            // ������ �� �����, ���������������. ������������ ��� ��������� ������ EntityAI � ItemBase (����� ������ �������� ���� ��������)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		            // ������ ������ ����� � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("MKII");				            // ������ ������ MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_MKII_10Rnd");	            // ������ ������ �������� � MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_MKII_10Rnd");	            // ������ ������ �������� � MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // ������ ������ �������� � AKM � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // ������ ������ �������� � AKM � ����� ��������� ���� � ���������
				itemCreated = NULL;															            // �������� �������� ���������� ����� ������ � ���, ����� ���� �� ����� ������������ �� �����
				itemCreated = player.GetHumanInventory().CreateInHands("akm");				            // ������ ������ AKM � ����
				if (itemCreated)															            // ���������, �������� �� ���
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 			            // ������ ������ �� AKM ������ ��� 11 � ������
					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 		            // ������ ������ �� AKM �����, ������� � ���������, � ������
					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );			            // ������ ������ �� AKM �����, ������� � ���������, � ������
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );			            // ������ ������ �� AKM �����, ������� � ���������, � ������
				}					
				break;
			}
			
			case 2: //Set with number 2  (��� � ������� 2)
			{
				break;
			}
			
			case 3: //Set with number 3   (��� � ������� 3)
			{
				break;
			}
			
			case 4: //Set with number 4   (��� � ������� 4)
			{
				break;
			}
			
			case 5: //Set with number 5   (��� � ������� 5)
			{
				break;
			}
			
			case 6: //Set with number 6   (��� � ������� 6)
			{
				break;
			}
			
			default: //Default starting spawn set (��� ����������� ��� ���� �������, ���� ������ ��������� - ���������� �����!)
			{
				//My_Custom_Spawn_Parameters.RemoveAllItems(player); // ����� ������� � ��������� ��� ��������� ����������� ��������� ������ ����������������� ������
				DefaultSets(player); // ��� ������ ����� ����� �� ������� ���� �������, �� ����������� � �������, ����������������� ��� ������
				break;
			}
		}
	}
	
	void SetRandomHealthItem(EntityAI itemCreated) // ������� ���������� � ��������� ��� �������� ��������� �������� ��������!
	{
		if ( itemCreated )
		{
			private int rndHlt = Math.RandomInt(55,6);
			itemCreated.SetHealth("","",rndHlt);
		}
	}
	
	void DefaultSets(PlayerBase player) // ������� ������ ���� �������, �� ����������� � ������������ �������!!!
	{
		EntityAI itemCreated = NULL;
		EntityAI itemCreated1 = NULL;
		ItemBase itemCasted = NULL;
		
		// ���� ������, ���� ��� ����� ������ ���� ����� ������ ��� ���� �������. ���� ��� ����� ����� ������������ � ��� ������� ���� �������������!
		// ��� ���������������, ���� ��� ���� - ����������������!
		// ������ ���� ����� ������ ������
		/*
		private array <vector>  spawnpoints = {"7500 0 7500",
			"7500 0 7500","7500 0 7500",
			"7500 0 7500"};
		private vector selected_spawnpoint = spawnpoints.GetRandomElement();
		player.SetPosition(selected_spawnpoint);
		*/
		// ����� ���� ����� ������ ������
		
		private int random_set_number = Math.RandomIntInclusive(1,3); // ���������� ������ ����� ���� �� 1 �� 6 ������������ (�� ��������� ������ case ����)
		switch( random_set_number ) //������� ��� (����� ������������ �������� �� 1 � ����, ������ �� 0 � �� -1)
		{
			case 1: //Set with number 1 (��� � ������� 1)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // ����� ������� � ��������� ��� ��������� ����������� ��������� ������ ����������������� ������
				itemCreated = player.GetInventory().CreateInInventory("MountainBag_Green"); 	        // ������ ������ � ���������� � ���������� itemCreated
				if (itemCreated)															            // ���������, �������� �� ������. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{                                                                                       
					SetRandomHealthItem(itemCreated);										            // ������ ������� ��������� ��������
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");	            // ��������� � ��������� ���������� ������� ������ � ���������� � ���������� itemCreated1
					if (itemCreated1)														            // ���������, ��������� �� ������ � �������, ������ � ��� � ���������� itemCreated1
					{                                                                                   
						SetRandomHealthItem(itemCreated1);									            // ������ ������ ��������� ��������
					}                                                                                   
					itemCreated1 = NULL;													            // �������� �������� ���������� ����� ������ � ���, ����� ��������� �������� ������ ���������
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");		            // ������ ������ ����� � ������ � ���������� � ���������� itemCreated1
					if (itemCreated1)														            // ���������, ��������� �� ����� � �������, ��� � ��� � ���������� itemCreated1
					{                                                                                   
						itemCasted = ItemBase.Cast(itemCreated1);							            // ��������� �������������� � ������ ����� ��� ������ � ������ ��� ��������, ��������� � ������ EntityAI ��� ������ ��� ������� SetQuantity, � � ��������� ItemBase ��� ����. ������� ��� ���� ��� � �������� ���� � ��� ��!
						itemCasted.SetQuantity(4);											            // ���������� ���������� ��� ��������� ������ ��� 4 �����
						SetRandomHealthItem(itemCreated);									            // ������ ������ ��������� ��������, ������� �������� � ������� EntityAI (��. � ����� �����)
					}
				}
				// ���������� itemCreated �� �������� �����, ��������� �� �� �� ���������� � �������� ����.
		        itemCreated = player.GetInventory().CreateInInventory("SantasHat");            	        // ������ ������ �������� ����
				itemCreated = player.GetInventory().CreateInInventory("SantasBeard");            	    // ������ ������ �����
		        itemCreated = player.GetInventory().CreateInInventory("OMNOGloves_Gray");		        // ������ ������ ��������
				itemCreated = player.GetInventory().CreateInInventory("TrackSuitPants_Green");		    // ������ ������ �����
				itemCreated = player.GetInventory().CreateInInventory("Sneakers_Green");	            // ������ ������ �����
				itemCreated = player.GetInventory().CreateInInventory("ChernarusSportShirt");	        // ������ ������ ������				
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("PlateCarrierVest"); 	            // ������ �����
				if (itemCreated)															            // ���������, ��������� �� �����. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 			    // ������ ������ � ������
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierPouches" ); 		        // ������ ������� � ������
					
				}
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MilitaryBelt"); 	                // ������ ������
				if (itemCreated)															            // ���������, �������� �� ������. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "NylonKnifeSheath" ); 			        // ������ ����� � ������
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 		        // ������ ������ � ������
					
				}
				itemCreated = NULL;
				//itemCasted = ItemBase.Cast(itemCreated);									            // ������ �� �����, ���������������. ������������ ��� ��������� ������ EntityAI � ItemBase (����� ������ �������� ���� ��������)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		            // ������ ������ ����� � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("MKII");				            // ������ ������ MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_MKII_10Rnd");	            // ������ ������ �������� � MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_MKII_10Rnd");	            // ������ ������ �������� � MKII
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // ������ ������ �������� � AKM � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // ������ ������ �������� � AKM � ����� ��������� ���� � ���������
				itemCreated = NULL;															            // �������� �������� ���������� ����� ������ � ���, ����� ���� �� ����� ������������ �� �����
				itemCreated = player.GetHumanInventory().CreateInHands("akm");				            // ������ ������ AKM � ����
				if (itemCreated)															            // ���������, �������� �� ���
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 			            // ������ ������ �� AKM ������ ��� 11 � ������
					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 		            // ������ ������ �� AKM �����, ������� � ���������, � ������
					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );			            // ������ ������ �� AKM �����, ������� � ���������, � ������
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );			            // ������ ������ �� AKM �����, ������� � ���������, � ������
				}					
				break;
			}
			
			case 2: //Set with number 2  (��� � ������� 2)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // ����� ������� � ��������� ��� ��������� ����������� ��������� ������ ����������������� ������
				itemCreated = player.GetInventory().CreateInInventory("MountainBag_Green"); 	            // ������ ������ � ���������� � ���������� itemCreated
				if (itemCreated)															            // ���������, �������� �� ������. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{                                                                                       
					SetRandomHealthItem(itemCreated);										            // ������ ������� ��������� ��������
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");	            // ��������� � ��������� ���������� ������� ������ � ���������� � ���������� itemCreated1
					if (itemCreated1)														            // ���������, ��������� �� ������ � �������, ������ � ��� � ���������� itemCreated1
					{                                                                                   
						SetRandomHealthItem(itemCreated1);									            // ������ ������ ��������� ��������
					}                                                                                   
					itemCreated1 = NULL;													            // �������� �������� ���������� ����� ������ � ���, ����� ��������� �������� ������ ���������
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");		            // ������ ������ ����� � ������ � ���������� � ���������� itemCreated1
					if (itemCreated1)														            // ���������, ��������� �� ����� � �������, ��� � ��� � ���������� itemCreated1
					{                                                                                   
						itemCasted = ItemBase.Cast(itemCreated1);							            // ��������� �������������� � ������ ����� ��� ������ � ������ ��� ��������, ��������� � ������ EntityAI ��� ������ ��� ������� SetQuantity, � � ��������� ItemBase ��� ����. ������� ��� ���� ��� � �������� ���� � ��� ��!
						itemCasted.SetQuantity(4);											            // ���������� ���������� ��� ��������� ������ ��� 4 �����
						SetRandomHealthItem(itemCreated);									            // ������ ������ ��������� ��������, ������� �������� � ������� EntityAI (��. � ����� �����)
					}
				}
				// ���������� itemCreated �� �������� �����, ��������� �� �� �� ���������� � �������� ����.
		        itemCreated = player.GetInventory().CreateInInventory("SantasHat");            	        // ������ ������ �������� ����
				itemCreated = player.GetInventory().CreateInInventory("SantasBeard");            	    // ������ ������ �����
		        itemCreated = player.GetInventory().CreateInInventory("OMNOGloves_Gray");		        // ������ ������ ��������
				itemCreated = player.GetInventory().CreateInInventory("TrackSuitPants_Green");		    // ������ ������ �����
				itemCreated = player.GetInventory().CreateInInventory("Sneakers_Green");	            // ������ ������ �����
				itemCreated = player.GetInventory().CreateInInventory("ChernarusSportShirt");	        // ������ ������ ������				
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("PlateCarrierVest"); 	            // ������ �����
				if (itemCreated)															            // ���������, ��������� �� �����. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" ); 			    // ������ ������ � ������
					itemCreated.GetInventory().CreateAttachment( "PlateCarrierPouches" ); 		        // ������ ������� � ������
					
				}
				itemCreated = NULL;
				//itemCasted = ItemBase.Cast(itemCreated);									            // ������ �� �����, ���������������. ������������ ��� ��������� ������ EntityAI � ItemBase (����� ������ �������� ���� ��������)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		            // ������ ������ ����� � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // ������ ������ �������� � AKM � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		            // ������ ������ �������� � AKM � ����� ��������� ���� � ���������
				itemCreated = NULL;															            // �������� �������� ���������� ����� ������ � ���, ����� ���� �� ����� ������������ �� �����
				itemCreated = player.GetHumanInventory().CreateInHands("akm");				            // ������ ������ AKM � ����
				if (itemCreated)															            // ���������, �������� �� ���
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 			            // ������ ������ �� AKM ������ ��� 11 � ������
					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 		            // ������ ������ �� AKM �����, ������� � ���������, � ������
					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );			            // ������ ������ �� AKM �����, ������� � ���������, � ������
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );			            // ������ ������ �� AKM �����, ������� � ���������, � ������
				}					
				break;
			}
			
			case 3: //Set with number 3   (��� � ������� 3)
			{
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // ����� ������� � ��������� ��� ��������� ����������� ��������� ������ ����������������� ������
				itemCreated = player.GetInventory().CreateInInventory("CoyoteBag_Green"); 	// ������ ������ � ���������� � ���������� itemCreated
				if (itemCreated)															// ���������, �������� �� ������. ���� �� ��������, ���������� itemCreated ����� �� ����� � �������� �������
				{
					SetRandomHealthItem(itemCreated);												// ������ ������� ��������� ��������
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");			// ��������� � ��������� ���������� ������� ������ � ���������� � ���������� itemCreated1
					if (itemCreated1)																// ���������, ��������� �� ������ � �������, ������ � ��� � ���������� itemCreated1
					{
						SetRandomHealthItem(itemCreated1);												// ������ ������ ��������� ��������
					}
					itemCreated1 = NULL;															// �������� �������� ���������� ����� ������ � ���, ����� ��������� �������� ������ ���������
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");				// ������ ������ ����� � ������ � ���������� � ���������� itemCreated1
					if (itemCreated1)																// ���������, ��������� �� ����� � �������, ��� � ��� � ���������� itemCreated1
					{
						itemCasted = ItemBase.Cast(itemCreated1);										// ��������� �������������� � ������ ����� ��� ������ � ������ ��� ��������, ��������� � ������ EntityAI ��� ������ ��� ������� SetQuantity, � � ��������� ItemBase ��� ����. ������� ��� ���� ��� � �������� ���� � ��� ��!
						itemCasted.SetQuantity(4);														// ���������� ���������� ��� ��������� ������ ��� 4 �����
						SetRandomHealthItem(itemCreated);												// ������ ������ ��������� ��������, ������� �������� � ������� EntityAI (��. � ����� �����)
					}
				}
				// ���������� itemCreated �� �������� �����, ��������� �� �� �� ���������� � �������� ����.
				itemCreated = player.GetInventory().CreateInInventory("TTSKOPants");		// ������ ������ �����
				itemCreated = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");	// ������ ������ ������
				itemCreated = player.GetInventory().CreateInInventory("CombatBoots_Black");	// ������ ������ �����
				//itemCasted = ItemBase.Cast(itemCreated);										// ������ �� �����, ���������������. ������������ ��� ��������� ������ EntityAI � ItemBase (����� ������ �������� ���� ��������)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		// ������ ������ ����� � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("FNX45");				// ������ ������ FNX � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// ������ ������ �������� � FNX � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// ������ ������ �������� � FNX � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		// ������ ������ �������� � AKM � ����� ��������� ���� � ���������
				itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");		// ������ ������ �������� � AKM � ����� ��������� ���� � ���������
				itemCreated = NULL;															// �������� �������� ���������� ����� ������ � ���, ����� ���� �� ����� ������������ �� �����
				itemCreated = player.GetHumanInventory().CreateInHands("akm");				// ������ ������ AKM � ����
				if (itemCreated)															// ���������, �������� �� ���
				{
					itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 				// ������ ������ �� AKM ������ ��� 11 � ������
					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 			// ������ ������ �� AKM �����, ������� � ���������, � ������
					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );				// ������ ������ �� AKM �����, ������� � ���������, � ������
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );				// ������ ������ �� AKM �����, ������� � ���������, � ������
				}					
				break;
			}
			
			case 4: //Set with number 4   (��� � ������� 4)
			{
				break;
			}
			
			case 5: //Set with number 5   (��� � ������� 5)
			{
				break;
			}
			
			case 6: //Set with number 6   (��� � ������� 6)
			{
				break;
			}
			
			default: //Default starting spawn set (��� ����������� ��� ���� �������, � ������ ���� �� ���� �� ����� ���� �� �����.
			{
				//My_Custom_Spawn_Parameters.RemoveAllItems(player); // ����� ������� � ��������� ��� ��������� ����������� ��������� ������ ����������������� ������
				
				break;
			}
		}
	}
}