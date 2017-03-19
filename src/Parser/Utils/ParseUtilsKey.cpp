#include "ParseUtilsKey.h"
#include <cctype>
#include "FileUtils.h"
#include "Game.h"
#include "GameUtils.h"
#include "SFMLUtils.h"
#include "Utils.h"

namespace Parser
{
	using namespace rapidjson;
	using namespace Utils;

	Anchor getAnchorKey(const Value& elem, const char* key, Anchor val)
	{
		if (elem.HasMember(key) == true)
		{
			const auto& keyElem = elem[key];
			if (keyElem.IsString() == true)
			{
				return GameUtils::getAnchor(keyElem.GetString(), val);
			}
			else if (keyElem.IsArray() == true)
			{
				Anchor ret = Anchor::None;
				for (const auto& arrElem : keyElem)
				{
					ret |= GameUtils::getAnchor(getStringVal(arrElem).c_str(), val);
				}
				return ret;
			}
		}
		return val;
	}

	bool getBoolKey(const Value& elem, const char* key, bool val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsBool() == true)
		{
			return elem[key].GetBool();
		}
		return val;
	}

	double getDoubleKey(const Value& elem, const char* key, double val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsDouble() == true)
		{
			return elem[key].GetDouble();
		}
		return val;
	}

	float getFloatKey(const Value& elem, const char* key, float val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsFloat() == true)
		{
			return elem[key].GetFloat();
		}
		return val;
	}

	int getIntKey(const Value& elem, const char* key, int val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsInt() == true)
		{
			return elem[key].GetInt();
		}
		return val;
	}

	int64_t getInt64Key(const Value& elem, const char* key, int64_t val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsInt64() == true)
		{
			return elem[key].GetInt64();
		}
		return val;
	}

	const char* getStringCharKey(const Value& elem,
		const char* key, const char* val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsString() == true)
		{
			return elem[key].GetString();
		}
		return val;
	}

	std::string getStringKey(const Value& elem,
		const char* key, const std::string& val)
	{
		return getStringCharKey(elem, key, val.c_str());
	}

	unsigned getUIntKey(const Value& elem, const char* key, unsigned val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsUint() == true)
		{
			return elem[key].GetUint();
		}
		return val;
	}

	uint64_t getUInt64Key(const Value& elem, const char* key, uint64_t val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsUint64() == true)
		{
			return elem[key].GetUint64();
		}
		return val;
	}

	sf::IntRect getIntRectKey(const Value& elem,
		const char* key, const sf::IntRect& val)
	{
		if (elem.HasMember(key) == true)
		{
			return getIntRectVal(elem[key], val);
		}
		return val;
	}

	sf::FloatRect getFloatRectKey(const Value& elem,
		const char* key, const sf::FloatRect& val)
	{
		if (elem.HasMember(key) == true)
		{
			return getFloatRectVal(elem[key], val);
		}
		return val;
	}

	sf::Color getColorKey(const Value& elem, const char* key, const sf::Color& val)
	{
		if (elem.HasMember(key) == true
			&& elem[key].IsString() == true)
		{
			try
			{
				return SFMLUtils::stringToColor(elem[key].GetString());
			}
			catch (std::exception ex) {}
		}
		return val;
	}

	std::vector<std::string> getStringVectorKey(const Value& elem, const char* key)
	{
		std::vector<std::string> vec;
		if (elem.HasMember(key) == true)
		{
			const auto& elemVal = elem[key];
			if (elemVal.IsArray() == true)
			{
				for (const auto& val : elemVal)
				{
					vec.push_back(val.GetString());
				}
			}
			else if (elemVal.IsString() == true)
			{
				vec.push_back(elemVal.GetString());
			}
		}
		return vec;
	}

	IgnoreResource getIgnoreResourceKey(const Value& elem,
		const char* key, IgnoreResource val)
	{
		if (elem.HasMember(key) == true)
		{
			const auto& keyElem = elem[key];
			if (keyElem.IsBool() == true)
			{
				if (keyElem.GetBool() == true)
				{
					return IgnoreResource::DrawAndUpdate;
				}
				else
				{
					return IgnoreResource::None;
				}
			}
			else if (keyElem.IsString() == true)
			{
				return GameUtils::getIgnoreResource(keyElem.GetString(), val);
			}
		}
		return val;
	}

	size_t getInventoryItemIndexKey(const Value& elem,
		const char* key, PlayerInventory inv)
	{
		if (elem.HasMember(key) == true)
		{
			return getInventoryItemIndexVal(elem[key], inv);
		}
		return 0;
	}

	InventoryPosition getInventoryPositionKey(const Value& elem,
		const char* key, InventoryPosition val)
	{
		if (elem.HasMember(key) == true)
		{
			return getInventoryPositionVal(elem[key], val);
		}
		return val;
	}

	ItemCoordInventory getItemCoordInventoryKey(const Value& elem, const char* key)
	{
		if (elem.HasMember(key) == true)
		{
			return getItemCoordInventoryVal(elem[key]);
		}
		return{};
	}

	ItemXY getItemXYKey(const Value& elem, const char* key, const ItemXY& val)
	{
		if (elem.HasMember(key) == true)
		{
			return getItemXYVal(elem[key], val);
		}
		return val;
	}

	PlayerDirection getPlayerDirectionKey(const Value& elem,
		const char* key, PlayerDirection val)
	{
		if (elem.HasMember(key) == true)
		{
			const auto& keyElem = elem[key];
			if (keyElem.IsString() == true)
			{
				return GameUtils::getPlayerDirection(keyElem.GetString(), val);
			}
		}
		return val;
	}

	PlayerInventory getPlayerInventoryKey(const Value& elem,
		const char* key, PlayerInventory val)
	{
		if (elem.HasMember(key) == true)
		{
			return getPlayerInventoryVal(elem[key], val);
		}
		return val;
	}

	PlayerItemMount getPlayerItemMountKey(const Value& elem,
		const char* key, PlayerItemMount val)
	{
		if (elem.HasMember(key) == true)
		{
			const auto& keyElem = elem[key];
			if (keyElem.IsString() == true)
			{
				return GameUtils::getPlayerItemMount(keyElem.GetString(), val);
			}
		}
		return val;
	}

	PlayerStatus getPlayerStatusKey(const Value& elem,
		const char* key, PlayerStatus val)
	{
		if (elem.HasMember(key) == true)
		{
			const auto& keyElem = elem[key];
			if (keyElem.IsString() == true)
			{
				return GameUtils::getPlayerStatus(keyElem.GetString(), val);
			}
		}
		return val;
	}

	Variable getVariableKey(const Value& elem, const char* key)
	{
		if (elem.HasMember(key) == true)
		{
			return getVariableVal(elem[key]);
		}
		return Variable();
	}
}