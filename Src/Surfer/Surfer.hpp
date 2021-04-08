class Surfer
{
public:
    Surfer(int init_pos);

    void set_position(int pos);
    
    int get_position() const;

private:
    int position;
};