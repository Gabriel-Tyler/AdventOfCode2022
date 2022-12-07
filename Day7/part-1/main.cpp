/**
 * Answer: 1723892
 */
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

using i64 = long long;

class Node
{
private:
    string name;
    i64 size;
    vector<Node*> children;
    vector<string> files;

public:
    Node(const string& newname) : name(newname), size(0) {}
    const string& Name() const { return name; }
    i64 Size() const { return size; }

    void AddSize(i64 newsize)
    {
        size += newsize;
    }
    void AddChild(Node* child) 
    { 
        children.push_back(child); 
    }
    int GetNumChildren() const
    {
        return children.size();
    }
    bool ContainsChild(const string& childname) 
    { 
        for (Node* c : children)
        {
            if (c->Name() == childname)
                return true;
        }
        return false;
    }
    Node* GetChild(const string& childname)
    {
        for (Node* c : children)
        {
            if (c->Name() == childname)
                return c;
        }
        return nullptr;
    }
    void AddFile(const string& filename)
    {
        files.push_back(filename);
    }
    bool ContainsFile(const string& filename)
    {
        for (string s : files)
        {
            if (s == filename)
                return true;
        }
        return false;
    }
};

void Solve()
{
    Node* root = new Node("/");
    vector<Node*> all_directories;
    vector<Node*> dir_stack;
    all_directories.push_back(root);
    //dir_stack.push_back(root);

    string line;
    bool done = false;
    bool read_line = false;
    while (!done)
    {
        if (!read_line)
        {
            getline(cin, line);
        }
        read_line = false;
        if (line.empty())
        {
            done = true;
            continue;
        }
        if (line[0] == '$')
        {
            string cmd = line.substr(2);
            if (cmd.find("cd") == 0)
            {
                string new_dir = cmd.substr(3);
                if (new_dir.find("/") == 0)
                {
                    dir_stack.clear();
                    dir_stack.push_back(root);
                }
                else if (new_dir.find("..") == 0)
                {
                    if (dir_stack.empty())
                    {
                        cerr << ".. when stack is empty\n";
                        done = true;
                        continue;
                    }
                    dir_stack.pop_back();
                }
                else
                {
                    if (dir_stack.empty())
                    {
                        cerr << "cd when directory stack is empty and not into '/'\n";
                        done = true;
                        continue;
                    }
                    Node* curr_dir = dir_stack.back();
                    if (curr_dir->ContainsChild(new_dir))
                    {
                        Node* child = curr_dir->GetChild(new_dir);
                        if (child)
                            dir_stack.push_back(child);
                    }
                }
            }
            else if (cmd.find("ls") == 0)
            {
                if (dir_stack.empty())
                {
                    cout << "calling ls on an empty stack; doing nothing\n";
                    continue;
                }
                read_line = true;
                while (getline(cin, line))
                {
                    if (line.empty())
                    {
                        done = true;
                        break;
                    }
                    if (line[0] == '$')
                    {
                        break;
                    }
                    istringstream iss(line);
                    string first, second;
                    iss >> first >> second;

                    Node* curr_dir = dir_stack.back();

                    if (first == "dir")
                    {
                        if (!curr_dir->ContainsChild(second))
                        {
                            Node* new_node = new Node(second);
                            all_directories.push_back(new_node);
                            curr_dir->AddChild(new_node);
                        }
                    }
                    else
                    {
                        if (curr_dir->ContainsFile(second))
                        {
                            break;
                        }

                        curr_dir->AddFile(second);
                        
                        i64 file_size = 0;
                        try
                        {
                            file_size = stoll(first);
                        }
                        catch (const exception& e)
                        {
                            cerr << "Exception when converting first string to i64: " << e.what() << '\n';
                            done = true;
                            break;
                        }
                        for (Node* dir : dir_stack)
                        {

                            if (dir)
                                dir->AddSize(file_size);
                            else
                            {
                                cerr << "dir pointer in stack is null\n";
                                done = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    i64 sum = 0;
    for (Node* dir : all_directories)
    {
        if (dir->Size() <= 100000)
            sum += dir->Size();
    }
    cout << sum << '\n';
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    Solve();
}













