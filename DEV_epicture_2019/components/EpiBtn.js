import React, {Component} from 'react';
import {
  Image,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,
  ScrollView,
} from 'react-native';


export default class EpiBtn extends Component<{}> {
  constructor (props) {
    super(props);
  }

  onPress = () => {
  }

  render() {
    return (
      <View style={styles.buttonContainer}>
        <TouchableOpacity onPress={this.onPress}>
          <Text style={styles.text}>{this.props.name}</Text>
        </TouchableOpacity>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  buttonContainer: {
    backgroundColor: 'grey',
  },
  text: {
    fontSize: 15,
  }
});
