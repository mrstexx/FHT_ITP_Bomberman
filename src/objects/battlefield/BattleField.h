#include <vector>
#include "..\blocks\BuildingBlock.h"

#ifndef SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_
#define SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_

class BattleField
{
	private:
		std::vector<std::vector<BuildingBlock>> battleField2D;
		void createBattleField ()
		{
			// TODO Stefan - to be continued, code refactoring
			sf::Texture texture;
			if (!texture.loadFromFile (
					"../../../res/Background items/topEdge.png"))
			{
				// error...
				std::cout << "Image error load" << std::endl;
			}
			BuildingBlock leftTopCorner (&texture, false);
			std::vector<BuildingBlock> firstFieldRow;
			for (int i = 0; i < NUMBER_OF_HORIZONTAL_BLOCKS; i++)
			{
				firstFieldRow.push_back (leftTopCorner);
			}
			this->battleField2D.push_back (firstFieldRow);
		}

	public:
		static const int NUMBER_OF_HORIZONTAL_BLOCKS = 15;
		static const int NUMBER_OF_VERTICAL_BLOCKS = 11;

		BattleField ();
		virtual ~BattleField ();

		std::vector<BuildingBlock> generateBattleField ()
		{
			// not 0 - only for test
			return this->battleField2D.at (0);
		}
};

#endif /* SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_ */