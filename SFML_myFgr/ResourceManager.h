#pragma once
#include "Singleton.h"
#include <string>
#include <unordered_map>

template <typename T>
class ResourceManager : public Singleton<ResourceManager<T>>
{
	friend Singleton<ResourceManager<T>>;
private:
	std::unordered_map<std::string, T*> resources;
	ResourceManager() = default;
	~ResourceManager() = default;
	ResourceManager(ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

public:
	static T Empty;

	void UnloadAll() {
		for (auto& pair : resources) {
			delete pair.second;
		}
		resources.clear();
	}

	
	bool Load(const std::string& id)
	{
		if (resources.find(id) != resources.end())
			return false;
		T* resource = new T();
		bool success = resource->loadFromFile(id);
		if (success) {
			resources.insert({ id, resource });
		}
		else {
			delete resource;
			return false;
		}
		return true;
	}

	bool UnLoad(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end()) 
		{
			return false;
		}

		delete it->second;
		resources.erase(it);
		return true;
	}

	T& Get(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
		{
			return Empty;
		}
		return *(it->second);
	}
};

template<typename T>
T ResourceManager<T>::Empty;