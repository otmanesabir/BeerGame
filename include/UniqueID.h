
//!  The UniqueID Class.
/*!
 * The UniqueID class handles all identification number information in the global scope.
 * This class makes sure all the ID's are unique.
*/

class UniqueID {
protected:
    static int nextID; /*!< The next ID open to use */
public:
    int id; /*!< The instances ID */

    //! Default constructor :
    /**
      The default constructor creates a default game instance.
    */
    UniqueID();
    //! Constructor :
    /**
     * This parametric consrtuctor is a tool to get the nextID and have an idea about it
     * or in order to create a faulty instance containing an invalid Player.
     * @param test true to get an instance with the next ID without affecting the count / false to return an invalid instance
     * of the game class.
    */
    explicit UniqueID(bool);
    //! Constructor :
    /*!
      The parametric constructor creates a custom game instance.
      @param nId the ID
      @param overwrite true to overwrite false to preform safe check - we don't suggest you overwrite.
    */
    explicit UniqueID(int, bool = false);
    //! Copy Constructor :
    /*!
     * Creates a copy of the given instance.
    */
    UniqueID(const UniqueID &orig);


    //! Overloaded casting operator.
    /**
     * Converts from type UniqueID to int.
     */
    operator int() const;
    //! Overloaded assignment operator.
    /**
     * Assigns an instance of UniqueID to the current instance.
     * @param orig ID of type UniqueID
     */
    UniqueID &operator=(const UniqueID &orig);
    //! Overloaded assignment operator.
    /**
     * Assigns an int value to the current instance.
     * @param x ID of type int
     */
    UniqueID &operator=(const int &x);

    //! Overloaded < operator.
    /**
     * Checks if this instance is smaller than the other.
     */
    bool operator<(const UniqueID &);
    //! Overloaded > operator.
    /**
     * Checks if this instance is bigger than the other.
     */
    bool operator>(const UniqueID &);
    //! Overloaded == operator.
    /**
     * Checks if this instance is equal than the other.
     */
    bool operator==(const UniqueID &);
    //! Overloaded <= operator.
    /**
     * Checks if this instance is less or equal than the other.
     */
    bool operator<=(const UniqueID &);
    //! Overloaded >= operator.
    /**
     * Checks if this instance is bigger or equal then the other.
     */
    bool operator>=(const UniqueID &);

};

